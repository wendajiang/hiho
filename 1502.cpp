/*
最大子矩阵的第一版
对于40%的数据，1 <= N, M <= 10  
对于100%的数据，1 <= N, M <= 250 1 <= K <= 2147483647 1 <= Aij <= 10000
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <climits>


using namespace std;

const int maxn = 300;

int matrix[maxn][maxn];
int sum[maxn][maxn];


int main(){
    int N, M, K;
    while(scanf("%d%d%d", &N, &M, &K) == 3){
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                scanf("%d", &matrix[i][j]);
                sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
//        for(int i = 1; i <= N; i++){
//            for(int j = 1; j <= M; j++){
//                cout << sum[i][j] << " ";
//            }
//            cout << endl;
//        }

        int block = -1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                for(int k = j; k <= M; k++){
                    int l = i; int r = N;
                    while(l < r){
                        int mid = (l + r + 1) / 2;
                        int tot = sum[mid][k] + sum[i][j] - sum[i][k] - sum[mid][j];
                        if(tot <= K){
                            l = mid;
                        }else r = mid - 1;
                    }
                    block = max(block, (l - i) * (k - j));
                }
        
        
        
        cout << block << endl;
    }
}