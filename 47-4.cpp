#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];

int pre[maxn];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    memset(pre, 0, sizeof(pre));
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }    
    set<int, greater<int> > container;
    ll ans = 0L;
    for(int L = 1; L <= n; L++){
        for(int R = L; R <= n; R++){
            container.insert(a[R]);
            if(R - L + 1 <= k) ans += pre[R] - pre[L] + a[L];
            else{
                int count = k;
                auto cur = container.begin();
                while(count--){
                    ans += *cur;
                    cur++;
                }
            }
        }
        container.clear();
    }
    printf("%Ld\n", ans);
}

int main(){
    solve();
    return 0;
}
