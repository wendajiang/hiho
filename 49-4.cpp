//第K小先序遍历
#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 31;
int a[maxn], tmp[maxn], rk[maxn];
ll f[maxn], k;
vector<int> ans;

void construct(int l, int r, ll c){
    if (l > r) return;
    int n = r - l + 1;
    memcpy(tmp, a + l, n * sizeof(int));
    sort(tmp, tmp + n);
    for (int i = l; i <= r; i++) {
        int r = lower_bound(tmp, tmp + n, a[i]) - tmp + 1;
        rk[r] = i;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int pos = rk[i];
        ll cnt = f[pos - l] * f[r - pos] * c;
        if (cnt >= k) {
            root = pos;
            break;
        }
        k -= cnt;
    }
    ans.push_back(a[root]);
    construct(l, root - 1, c * f[r - root]);
    construct(root + 1, r, c);
}

int main(){
    f[0] = 1;
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= i; j++) f[i] += f[j - 1] * f[i - j];
    }
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    construct(1, n, 1);
    for(auto i : ans) cout << i << endl;
    return 0;
}
