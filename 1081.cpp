#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
const int MAXM = 1e4 + 1;

int n, m, s, t;

int G[MAXN][MAXN];

int dist[MAXN];
bool vis[MAXN];

struct heapNode {
    int d, u;
    bool operator <(const heapNode& rhs) const {
        return d > rhs.d;
    }
};

void dijkstra(int s) {
    priority_queue<heapNode> Q;
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INT_MAX;
    }
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    Q.push((heapNode){0, s});
    while(!Q.empty()) {
        heapNode x = Q.top(); Q.pop();
        int u = x.u;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < MAXN; i++) {
            if (G[u][i] > 0) {
                if (dist[i] > dist[u] + G[u][i]) {
                    dist[i] = dist[u] + G[u][i];
                    Q.push((heapNode){dist[i], i});
                }
            }
        }
    }
}

void hh() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(G, -1, sizeof(G));
    for (int i = 0; i < m; i++) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        if(G[u][v] < 0 && G[v][u] < 0) {
            G[u][v] = len;
            G[v][u] = len;
        } else {
            G[u][v] = min(G[u][v], len);
            G[v][u] = min(G[v][u], len);
        }
    }
    dijkstra(s);

    printf("%d\n", dist[t]);
}

int main(){
    hh();
    return 0;
}
