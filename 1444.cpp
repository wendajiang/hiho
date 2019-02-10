#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long d[1001],c[1001][1001];
long long dfs(long long n)
{
    if(n==0)return 1;
    if(d[n])return d[n];
    for(int i=1;i<=n;i++)d[n]=(d[n]+c[n][i]*dfs(n-i)%MOD)%MOD;
    //printf("d[%lld]=%lld\n",n,d[n]);
    return d[n];
}
void init()
{
    memset(c,0,sizeof c);
    c[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
}
int main()
{
    init();
    long long n;
    cin>>n;
    memset(d,0,sizeof d);
    cout<<dfs(n)<<endl;
    return 0;
}
