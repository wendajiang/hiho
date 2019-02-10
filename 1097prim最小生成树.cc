#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
const int INF = 0x7fffffff;

int N;
int G[MAXN][MAXN];


bool vis[MAXN];
int dist[MAXN];

struct cmp {
	bool operator() (const int &a, const int &b) {
		if (dist[a] == dist[b]) return a < b;
		return dist[a] < dist[b];
	}
};

void prim() {
	memset(vis, 0, sizeof(vis));
	dist[1] = 0;
	for (int i = 2; i <= N; i++) 
		dist[i] = INF; 
	//auto cmp = [](const int &a, const int &b) { return dist[a] <= dist[b]; };
	set<int, cmp> st;
	for(int i = 1; i <= N; i++) st.insert(i);
	while (!st.empty()) {
		int x = *st.begin();
		st.erase(x);
		vis[x] = true;
		for (int y = 1; y <= N; y++) {
			if(y != x && !vis[y] && G[x][y] < dist[y]){
				st.erase(y);
				dist[y] = G[x][y];
				st.insert(y);
			}
		}
	}
	
	
}

int main () {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	prim();
	int res = 0;
	for (int i = 1; i <= N; i++) res += dist[i];
	printf("%d\n", res);
	return 0;
}