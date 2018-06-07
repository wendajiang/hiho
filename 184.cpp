// //暴力解法，二进制枚举子集
// #include <iostream>
// #include <cstring>
// #include <cstdio>

// const int maxn = 20 + 5;
// int N, X;
// int w[maxn];
// int vis[maxn];

// using namespace std;

// int main(){
//     while(scanf("%d%d", &N, &X) == 2 && N){
//         memset(vis, 0, sizeof(vis));
//         memset(w, 0 , sizeof(w));
//         int sum = 0;
//         for(int i = 0; i < N; i++) {
//             scanf("%d", &w[i]);
//             sum += w[i];
//         }
//         if(sum < X)
//             printf("-1\n");
//         else{
//             // ans = sum;
//             for(int i = 0; i < (1 << N); i++){
//                 int tmp = 0;
//                 for(int j = 0; j < N; j++){
//                     if(i & (1 << j)){
//                         tmp += w[j];
//                     }
//                 }
//                 if(tmp >= X && tmp < sum)
//                     sum = tmp;
//             }
//             printf("%d\n", sum);
//         }
        
//     }
    
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


const int maxn = 20 + 5;
int N, X;
int w[maxn];

const int maxX = 100 + 5;
int dp[maxn][maxX];   //表示前i个物品  能不能组成j价格



int main(){
    while(scanf("%d%d", &N, &X) == 2 && N){
        memset(dp, 0, sizeof(dp));
        memset(w, 0 , sizeof(w));
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &w[i]);
            sum += w[i];
        }
        if(sum < X){
            printf("-1\n");
            return 0;
        }
        ans = sum;
        dp[0][w[0]] = 1;
        dp[0][0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < maxX; j++){
                if(dp[i][j] == 1){
                    if(j + w[i + 1] < maxX){
                        dp[i + 1][j + w[i + 1]] = 1;
                        dp[i + 1][j] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < maxX; i++){
            if(dp[N - 1][i] >= X){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}