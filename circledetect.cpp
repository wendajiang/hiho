#include <bits/stdc++.h>
using namespace std;

const int MAXN =  1e5 + 1;

int T;
int N, M;

int color[MAXN]; // 0 white 1 gray 2 black
vector<int> G[MAXN];

void Clear(){
    for (int i = 0; i < MAXN; i++){
        color[i] = 0; 
        G[i].clear();
    }
}

bool dfs(int u){
    color[u] = 1;
    for (int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if (color[v] == 0) {
            if (dfs(v)) return true;
        } else if (color[v] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int main() {
    scanf("%d", &T);
    
    while(T--){
        scanf("%d%d", &N, &M);
        Clear();
        vector<int> sNode;
        for (int i = 0; i < M; i++) {
            int s, t;
            scanf("%d%d", &s, &t);
            G[s].push_back(t);
            sNode.push_back(s);
        }
        bool bFlag = false;
        for (int i = 0; i < sNode.size(); i++) {
            if (color[sNode[i]] == 0) {
                bFlag = dfs(sNode[i]);
                if (bFlag == true) break;
            }
        }
        if (bFlag) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}