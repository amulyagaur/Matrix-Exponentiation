#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
	void multiply(long long int F[2][2],long long int M[2][2])
	{
		long long int x = ((F[0][0]%MOD*M[0][0]%MOD)%MOD + (F[0][1]%MOD*M[1][0]%MOD)%MOD)%MOD;
		long long int y = ((F[0][0]%MOD*M[0][1]%MOD)%MOD + (F[0][1]%MOD*M[1][1]%MOD)%MOD)%MOD;
		long long int z = ((F[1][0]%MOD*M[0][0]%MOD)%MOD + (F[1][1]%MOD*M[1][0]%MOD)%MOD)%MOD;
		long long int w = ((F[1][0]%MOD*M[0][1]%MOD)%MOD + (F[1][1]%MOD*M[1][1]%MOD)%MOD)%MOD;

		F[0][0] = x;
		F[0][1] = y;
		F[1][0] = z;
		F[1][1] = w;
	}
	void power(long long int f[2][2],long long int n)
	{
		if(n==0 || n==1)
			return ;
		long long int m[2][2];
		m[0][0]=1;
		m[0][1]=1;
		m[1][0]=1;
		m[1][1]=0;
		power(f,n/2);
		multiply(f,f);
		
		if(n%2==1)
			multiply(f,m);
	}
//function to build the segment tree
void buildTree(long long int *tree,long long int *a,long long int index,long long int s,long long int e)
{
	//base case
	if(s>e)
		return;
	//reached leaf node
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	//now build the segment tree in bottom up manner
	long long int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= __gcd(tree[2*index],tree[2*index+1]);
	return;
}

//function to query the segment tree for RMQ
long long int query(long long int *tree,long long int index,long long int s,long long int e,long long int qs,long long int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return 0;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	long long int m = (s+e)/2;
	long long int left_ans = query(tree,2*index,s,m,qs,qe);
	long long int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return __gcd(left_ans,right_ans);
}

int main()
{
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long int *tree = new long long int[4*n+1];                                    //array to store the segment tree
    long long int index = 1;													//index of 1st node
    long long int s =0,e=n-1;
    buildTree(tree,a,index,s,e);
    while(q--)
    {
        long long l,r;
        cin>>l>>r;
        long long ans = query(tree,index,s,e,l-1,r-1);
        if(ans<=2)
        cout<<1<<endl;
        else
        {
            long long f[2][2]={{1,1},{1,0}};
            power(f,ans-2);
			cout<<(f[0][0]%MOD+f[0][1]%MOD)%MOD<<endl;
        }
    }
}
