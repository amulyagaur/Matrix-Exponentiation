#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000000
long long temp[10][10];
void multiply(long long mat1[10][10],long long mat2[10][10],long long k)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			temp[i][j]=0;
			for(int kk=0;kk<k;kk++)
				temp[i][j] = (temp[i][j]%MOD +  (mat1[i][kk]%MOD*mat2[kk][j]%MOD)%MOD)%MOD;
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
			mat1[i][j]=temp[i][j];
	}
}
void power(long long m[10][10],long long n,long long k,long long c[])
{
	if(n==0 || n==1)
		return 	;
	long long m1[10][10];
      	for(int i=0;i<k;i++)
      		m1[0][i]=c[i];
      	for(int i=1;i<k;i++)
      	{
      		for(int j=0;j<k;j++)
      		{
      			if((i-j)==1)
      				m1[i][j]=1;
      			else
      				m1[i][j]=0;
      		}
      	}
    power(m,n/2,k,c);
    multiply(m,m,k);
    if(n%2==1)
    	multiply(m,m1,k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
      long long k,n;
      cin>>k;
      long long b[k],c[k];
      for(int i=0;i<k;i++)
      	cin>>b[i];
      for(int i=0;i<k;i++)
      	cin>>c[i];
      cin>>n;
      if(n<=k)
      	cout<<b[n-1]<<endl;
      else
      {
      	long long m[10][10];
      	for(int i=0;i<k;i++)
      		m[0][i]=c[i];
      	for(int i=1;i<k;i++)
      	{
      		for(int j=0;j<k;j++)
      		{
      			if((i-j)==1)
      				m[i][j]=1;
      			else
      				m[i][j]=0;
      		}
      	}
      	power(m,n-k,k,c);
      	long long res =0;
      	for(int i=0;i<k;i++)
      		res = (res%MOD + m[0][i]%MOD*b[k-i-1]%MOD)%MOD;
      	cout<<res<<endl;
      }
    }
    return 0;
}
