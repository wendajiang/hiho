#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 1;
const int MAXM = 2e4 + 1;

int n, m;

struct Edge {
    int from, to;
    int cap, flow;
    Edge(int f, int t, int c): from(f), to(t), cap(c){
        flow = 0;
    }
};

vector<Edge> edges;
vector<int> G[MAXN]; // 图

int a[MAXN]; //当起点到i的可改进量
int p[MAXN]; // 最短路树上的p的入弧编号

void addEdge(int from, int to, int c) {
    edges.push_back(Edge(from, to, c));
    edges.push_back(Edge(to, from, 0)); // 反向弧
    int idx = edges.size() - 1;
    G[from].push_back(idx - 1);
    G[to].push_back(idx);
}

void init() { // 直接构造残存网络
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, c; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        addEdge(u, v, c);
    }
}

void maxFlow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(a, 0, sizeof(a));
        queue<int> Q;
        Q.push(s);
        a[s] = INT_MAX;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!a[e.to] && e.cap > e.flow) {
                    p[e.to] = G[x][i];
                    a[e.to] = min(a[x], e.cap - e.flow);
                    Q.push(e.to);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t]; //反向弧
        }
        flow += a[t];
    }
    printf("%d\n", flow);
}

int main(){
    init();
    maxFlow(1, n);
    return 0;
}
