#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
char ss[maxn];

int dp[maxn][maxn];

int main(){
    while(scanf("%s", ss)){
        int len = strlen(ss);
        
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                if(ss[i] == 'a' && (ss[j] == 'e' || ss[j] == 'i')){
                    dp[i][j] = 1;
                }else if(ss[i] == 'e' && ss[j] == 'i'){
                    dp[i][j] = 1;
                }else if(ss[i] == 'o' && ss[j] == 'u'){
                    dp[i][j] = 1;
                }
            }
        }
        cout << dp[len - 1][len - 2] << endl;

    }
    return 0;
}
