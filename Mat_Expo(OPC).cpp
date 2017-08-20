// code for solving the recurrence relation f(n) = f(n-1)+f(n-2)+f(n-3) using matrix exponentiation :)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
long long temp[3][3];
void multiply(long long mat1[3][3],long long mat2[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<3;k++)
				temp[i][j] = (temp[i][j]%MOD +  (mat1[i][k]%MOD*mat2[k][j]%MOD)%MOD)%MOD;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			mat1[i][j]=temp[i][j];
	}
}
void power(long long mat[3][3],long long n)
{
	if(n<2)
		return ;
	long long id[3][3]={{1,1,1},{1,0,0},{0,1,0}};
	power(mat,n/2);
	multiply(mat,mat);
	if(n&1)
		multiply(mat,id);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
    	long long n;
    	cin>>n;
    	if(n==1)
    		cout<<1<<endl;
    	else
    		if(n==2)
    			cout<<2<<endl;
    		else
    			if(n==3)
    				cout<<4<<endl;
    			else
    			{
    				long long mat[3][3]={{1,1,1},{1,0,0},{0,1,0}};
    				power(mat,n-3);
    				cout<<(4*mat[0][0]%MOD+2*mat[0][1]%MOD+mat[0][2]%MOD)%MOD<<endl;
    			}
    }
    return 0;
}
