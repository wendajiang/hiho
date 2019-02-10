//求最长单调递减子序列

//最简单的版本，O(n*n)的时间复杂度，TLE
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;

int N;
int v[maxn];

int d[maxn];



int main(){
    while(scanf("%d", &N) == 1 && N){
        int ans = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }
        memset(d, 0, sizeof(d));
        // d[0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= i; j++){
                if(v[i] < v[j]){
                    d[i] = max(d[i], d[j] + 1);
                }
            }
            ans = max(ans, d[i]);
        }

        printf("%d\n", N - ans - 1);
    }
}