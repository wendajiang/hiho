#include <bits/stdc++.h>
using namespace std;

const int MAXM = 10e6 + 1;
const int MAXN=  10e5 + 1;

typedef struct edge {
	int from, to;
	int w;
}edge;

edge E[MAXM];
int N, M;

int father[MAXN];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void init() {
	for (int i = 1; i <= N; i++) {
		father[i] = i;
	}
}

int Find(int x) {
	if (x == father[x]) return x;
	return father[x] = Find(father[x]);
}

bool Same(int x, int y) {
	return Find(x) == Find(y);
}

void unionSet(int x, int y) {
	int u = Find(x), v = Find(y);
	if (u == v) return;
	father[u] = v;
}


long long Kruskal() {
	long long res = 0;
	sort(E + 1, E + 1 + M, cmp);
	for (int i = 1; i <= M; i++){
		if (Same(E[i].from, E[i].to)) continue;
		unionSet(E[i].from, E[i].to);
		res += E[i].w;
	}
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	init();
	for (int i = 1; i <= M; i++){
		scanf("%d%d%d", &E[i].from, &E[i].to, &E[i].w);
	}
	long long res = Kruskal();
	printf("%ld\n", res);

	return 0;
}