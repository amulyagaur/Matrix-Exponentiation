#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long temp[4][4];
void multiply(long long mat1[4][4],long long mat2[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			temp[i][j]=0;
			for(int kk=0;kk<4;kk++)
				temp[i][j] = (temp[i][j] +  (mat1[i][kk]*mat2[kk][j]))%MOD;
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			mat1[i][j]=temp[i][j];
	}
}
void power(long long m[4][4],long long n)
{
	if(n==0 || n==1)
		return 	;
	long long m1[4][4]={{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
     
    power(m,n/2);
    multiply(m,m);
    if(n%2==1)
    	multiply(m,m1);
}
long long get(int n)
{
	if(n<=2)
		return 0;
	else
		if(n==3)
			return 1;
		else
		{
			long long m[4][4]={{1,1,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
			power(m,n-3);
			return m[0][0];
		}
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	long long res1,res2;
    	int n,m;

    	scanf("%d %d",&n,&m);
    	n--;
    	res1 = ((get(m) + get(m+3) - get(m+1) -1 +MOD) *333333336)%MOD;
    	if(n>=0)
    	res2 = ((get(n) + get(n+3) - get(n+1) -1 +MOD) *333333336)%MOD;
    	else
    		res2 =0;
    	printf("%lld\n",(res1-res2+MOD)%MOD);
    }
    return 0;
}
