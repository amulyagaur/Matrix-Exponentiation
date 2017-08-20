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
	long long power_mod(long long a,long long n)
{
	if(n==0)
		return 1;
	long long int ans = power_mod(a,n/2);
	ans = (ans%MOD*ans%MOD)%MOD;
	if(n%2==1)
		ans = (ans%MOD*a%MOD)%MOD;
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long fib[100];
    long long a[100]={0};
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=52;i++)
    {
    	fib[i]=fib[i-1]+fib[i-2];
    }
    a[0]=0;
    for(int i=1;i<=52;i++)
    {
    	if((fib[i]-fib[i-1])>1)
    		a[i]=a[i-1]+(fib[i]-fib[i-1]-1);
    	else
    		a[i]=a[i-1];
    }
    
    
    int t;
    cin>>t;
    while(t--)
    {
    	long long n,res,a1,b1;
    	cin>>n;
    	res = lower_bound(a,a+51,n)-a;
    	a1 = fib[res]-(a[res]-n+1);
    	if(n<3)
    		b1 =1;
    	else
    	{
    		long long f[2][2]={{1,1},{1,0}};
    		power(f,n-2);
    		b1 = (f[0][0]%MOD+f[0][1]%MOD)%MOD;
    	}
    	cout<<(long long)power_mod(a1,b1)<<endl;
    }
    
    return 0;
}
