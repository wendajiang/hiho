#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 500 + 1;
const int MAXM = 10e5 + 1;
int N, M;
int need[MAXN];
int value[MAXN];

//int best[MAXN][MAXM];
int best[MAXM];

void init() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &need[i], &value[i]);
	}
	memset(best, 0, sizeof(best));
	/*
	for (int j = 0; j <= M; j++) {
		best[0][j] = 0;
	}*/
	
}

/*
void dp_01() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j < need[i])
				best[i][j] = best[i - 1][j];
			else  
				best[i][j] = max(best[i - 1][j], best[i - 1][j - need[i]] + value[i]);
		}
	}
	printf("%d\n", best[N][M]);
}
*/

void dp_01() {
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= need[i]; j--) {
			best[j] = max(best[j], best[j - need[i]] + value[i]);
		}
	}
	
	printf("%d\n", best[M]);
}

int main() {
  init();
  dp_01();
  return 0;
}