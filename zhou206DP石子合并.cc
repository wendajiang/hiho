#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 1;

int dp[MAXN][MAXN];

int n;

int main () {
	scanf("%d", &n);
	for (int l = n; l > 0; l--) {
		for (int r = l + 1; r <= n; r++) {
			dp[l][r] = INT_MAX;
			for (int kk = l; kk <= r; kk++) {
				int s = 0;
				if(kk > l) s = max(s, dp[l][k - 1]);
				if(kk < r) s = max(s, dp[kk + 1][r]);
				dp[l][r] = min(dp[l][r], s + kk);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}