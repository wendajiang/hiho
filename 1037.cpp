#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5050 + 1;

int a[100 + 1][100 + 1];

int dp[100 + 1][100 + 1]; //第i层第j个房间的最大奖券数量

int main(){
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    int ans = 0;
    for (int i =1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}
