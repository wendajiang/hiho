#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 1;
const int MAXM = 1e5 + 1;

typedef long long LL;

LL dp[MAXM];  //取到第n件，在使用了m张券的时候，最大value

int need[MAXN];
int value[MAXN];

void hh() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &need[i], &value[i]);
    }
    for (int i = 0; i < MAXM; i++) 
        dp[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = need[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
        }
    }
    printf("%lld\n", dp[m]);
}

int main(){
    hh();
    return 0;
}
