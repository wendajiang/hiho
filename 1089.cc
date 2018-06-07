#include <bits/stdc++.h> 
using namespace std; 
const int MAXN = 100 + 1;
const int MAXM = 1e3 + 1;

int G[MAXN][MAXN];
// int res[MAXN][MAXN];

int N, M;

void init() {
	
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) G[i][j] = 0;
			else G[i][j] = 1e7;
		}
	}

	for (int i = 0, from, to, l; i < M; i++) {
		scanf("%d%d%d", &from, &to, &l);
		G[from][to] = min(G[from][to], l);
		G[to][from] = min(G[to][from], l);
	}
}

void floyd(){
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					// res[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", G[i][j] == 1e7 ? 0 : G[i][j]);
		}
		printf("\n");
	}
}
int main() {
	init();
	floyd();
	return 0;
}
