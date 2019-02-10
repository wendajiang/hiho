#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m, fa[maxn], r[maxn];
vector<int> T[maxn];
bool vis[maxn];

void dfs(int x){
    sort(T[x].begin(), T[x].end());
    for(int i = 0; i < T[x].size(); i++){
        dfs(T[x][i]);
    }
    r[m ++] = x;
}

void solve(){
    scanf("%d", &n);
    m = 0;
    memset(fa, 0, sizeof(fa));
    memset(r, 0, sizeof(r));
    memset(vis, false, sizeof(vis));
    for(int i = 1; i < n; i++){
        int p, c;
        scanf("%d%d", &p, &c);
        T[p].push_back(c);
        fa[c] = p;
    }
    for(int i = 0; i <= n; i++){
        if(fa[i] == 0) dfs(i);
    }
    for(int i = 0; i < n; i++){
        if(T[r[i]].size() == 0){
            for(int j = r[i]; j != 0 && !vis[j]; j = fa[j]){
                printf("%d\n", j);
                vis[j] = true;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
