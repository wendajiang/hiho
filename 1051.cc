#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 1;
int N, M;
int a[MAXN];

int main() {
	int kase;
	scanf("%d",  &kase);
	while (kase--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		if (N <= M) {
			printf("100\n");
		}else{
			int Max = 0;
			for (int i = M; i < N; i++) {
				Max = max(Max, a[i] - a[i - M - 1] - 1);
			}			
			printf("%d\n", Max);
		}
	}	
	return 0;
}