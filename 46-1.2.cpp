#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,m,k,t,dp[5];
char a[maxn];
int main()
{
    int i,j;
    scanf("%s",a+1);
    for(i=1;a[i];i++)
    {
        if(a[i]=='a')dp[0]++;
        if(a[i]=='e')dp[1]=max(dp[0],dp[1])+1;
        if(a[i]=='i')dp[2]=max({dp[2],dp[1],dp[0]})+1;
        if(a[i]=='o')dp[3]++;
        if(a[i]=='u')dp[4]=max(dp[4],dp[3])+1;
    }
    printf("%d\n",dp[2]+dp[4]);
    return 0;
}        cout << ans << endl;
        memset(ss, 0, sizeof(ss));

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,m,k,t,dp[5];
char a[maxn];
int main()
{
    int i,j;
    scanf("%s",a+1);
    for(i=1;a[i];i++)
    {
        if(a[i]=='a')dp[0]++;
        if(a[i]=='e')dp[1]=max(dp[0],dp[1])+1;
        if(a[i]=='i')dp[2]=max({dp[2],dp[1],dp[0]})+1;
        if(a[i]=='o')dp[3]++;
        if(a[i]=='u')dp[4]=max(dp[4],dp[3])+1;
    }
    printf("%d\n",dp[2]+dp[4]);
    return 0;
}