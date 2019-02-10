#include <bits/stdc++.h> 
 
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 8, MAXM = 1024 + 8;
 
int val[MAXN], dp[MAXN][MAXM];
 
int main() {
    int n, m, q, i, j, ans = 0;
    cin >> n >> m >> q;
    for(i = 0; i < n; i++){
        cin >> val[i];
    }
    int t, cnt, maxm = (1<< m) - 1;
 
    for(i = 0; i < n; i++){
        for(j = 0; j <= maxm; j++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = val[i];
                break;
            }
            if(i < m && j > (1<< (i+1)) - 1) break;
            t = j;
            cnt = 0;
            while(t){
                if(t & 1) cnt++;
                t >>= 1;
            }
            if(cnt > q) continue;
            t = j;
            t >>= 1;
            if(i < m) dp[i][j] = dp[i-1][t] + (j % 2 == 1 ? val[i] : 0);
            else dp[i][j] = max(dp[i-1][t], dp[i-1][t + (1<<(m-1))]) + (j % 2 == 1 ? val[i] : 0);
        }
    }
    for(j = 0; j <= maxm; j++) ans = max(ans, dp[n-1][j]);
    cout << ans << endl;
    return 0;
}

/*
题意：给出一个序列，选出一部分值，连续的m个数里最短选取q个，求选出的值的和的最大值。



状态压缩dp

dp[i][j] 表示当前考虑第i个数，且以i结尾的连续m个数的情况储存在j里，j用二进制表示以后比如m=5， 10100表示序列选了i-4, i-2,没有选i-3, i-1, i.

状态转移的时候，先判断j里有几个1，如果cnt <= q,则为合法状态，

t = j >> 1 表示当前状态j表示的 前 m-1个数的情况(不包括第i个数)

如果 i < m 则直接， dp[i][j] = dp[i-1][t] + (j % 2 == 1 ? val[i] : 0)

否则 dp[i][j] = max(dp[i-1][t], dp[i-1][t + (1<<(m-1))]) +  (j % 2 == 1 ? val[i] : 0), 

其中dp[i-1][t]表示第i-m个数(即上一个i区间的第1个数)没有选，  dp[i-1][t + (1<<(m-1))]) 表示第i-m个数选了。

复杂度 O(n*1024*10)


*/