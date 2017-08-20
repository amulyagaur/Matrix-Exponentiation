#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void multiply(long long int F[2][2],long long int M[2][2])
{
	long long int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	long long int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	long long int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	long long int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int mat[2][2]={{1,1},{1,0}};
    long long n;
    cin>>n;
    power(mat,n-1);
    cout<<mat[0][0]+mat[0][1]<<endl;
    return 0;
}