#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e5 + 1;
const int MAXM = 10e6 + 1;

typedef struct edge {
	int from, to;
	int w;
	edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}
	edge() {}
	bool operator < (const edge &a) const {
		return a.w < w;
	}
}edge;

priority_queue<edge> que;

vector<edge> G[MAXN];

bool vis[MAXN];

int N, M;
int s_u;

int prim() {
	int res = 0;
	vis[s_u] = 1;
	for (int i = 0; i < G[s_u].size(); i++) {
		que.push(G[s_u][i]);
	}
	while (!que.empty()) {
		edge e = que.top();
		que.pop();
		if (vis[e.to]) continue;
		vis[e.to] = 1;
		res += e.w;
		for (int i = 0; i < G[e.to].size(); i++) {
			que.push(G[e.to][i]);
		}
	}
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (i == 1) s_u = u;
		G[u].push_back(edge(u, v, w));
		G[v].push_back(edge(v, u, w));
	}
	int res = prim();
	printf("%d\n", res);
	return 0;
}