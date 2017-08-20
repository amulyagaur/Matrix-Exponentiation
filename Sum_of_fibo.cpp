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
	long long get_nth(long long f[2][2],long long n)
	{
		if(n==0)
			return 0;
		else
			if(n==1)
				return 1;
			else
				if(n==2)
					return 1;
				else
					if(n==3)
						return 2;
				else
				{
	    			power(f,n-2);
	    			return f[0][1]+f[0][1]-1;
				}
		
	    //cout<<f[0][0]+f[0][1]<<endl;
	}
	int main()
	{
		int t;
		cin>>t;
		while(t--)
		{
			long long a,b,n1,n2,l,r;
			cin>>a>>b;
			n1 = a+1;
			n2 = b+2;	
			if(n1<2)
			l=n1;
		else
			if(n1==2)
				l=1;
		else
		{
			long long f[2][2]= {{1,1},{1,0}};
			power(f,n1-2);
			l=f[0][0]+f[0][1];
		}

		if(n2<2)
			r=n2;
		else
			if(n2==2)
				r=1;
		else
		{
			long long f1[2][2]= {{1,1},{1,0}};
			power(f1,n2-2);
			r=f1[0][0]+f1[0][1];
		}
		long long res = (r%MOD-l%MOD+MOD)%MOD;
		cout<<res<<endl;
		}
		/*
		int n;
		cin>>n;
		if(n<2)
			cout<<n<<endl;
		else
			if(n==2)
				cout<<1<<endl;
		else
		{
			long long f[2][2]= {{1,1},{1,0}};
			power(f,n-2);
			cout<<f[0][0]+f[0][1]<<endl;
		}
			
		*/
		return 0;
	}