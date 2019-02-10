#include <bits/stdc++.h>
using namespace std
typedef long long ll;
struct seg {
	int l, r, n;
	set(int x, int y, int z): l(x), r(y), n(z) {}
};
bool test(const vector<int>&p, const vector<seg> &q, int maxN) {
	list<seg> segs;
	int N = p.size(), M = q.size();
	if(M == 0) return true;
	int li = 0, ln = q[0].n;
}
int main() {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		scanf("%d%d", &N, &R);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &X[i], &Y[i]);
		}
	}
	return 0;
}