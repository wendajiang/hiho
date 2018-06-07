#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N, M, K;
int a[maxn];
int wall[10 + 5];

bool walk(int T){
    for(int i = 0; i < K; i++) wall[i] = M;
    int cur = 0;
    
    for(int i = 0; i < N; i++){
        if(wall[cur] + T < M) wall[cur] += T;
        else wall[cur] = M;
        wall[cur] -= a[i];
        if(wall[cur] <= 0) cur++;
        if(cur >= K) return false;
    }
    return true;
}

int main(){
    while(scanf("%d%d%d", &N, &M, &K) == 3 && N){
        for(int i = 0; i < N; i++) scanf("%d", &a[i]);
        memset(wall, 0, sizeof(wall));
        int T = -1;
        int ans = -1;
        int l = 0, r = M;
        while(l < r){
            T = (l + r) / 2;
            int res = walk(T);
            if(res){
                r = T;
            }else{
                l = T + 1;
            }
        }
        if(walk(r)) if(r == 0) printf("1\n"); else printf("%d\n", r);
        else printf("-1\n");
    }
    return 0;
}
