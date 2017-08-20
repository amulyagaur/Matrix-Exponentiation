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
	
	int main()
	{
		int n;
		cin>>n;
		long long a[n],ans=0;
		for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans= __gcd(ans,a[i]);
        }
        //ans--;
		
		
		if(ans<=2)
			cout<<1<<endl;
		
		else
		{
			long long f[2][2]= {{1,1},{1,0}};
			power(f,ans-2);
			cout<<(f[0][0]%MOD+f[0][1]%MOD)%MOD<<endl;
		}
			
		
		return 0;
	}
