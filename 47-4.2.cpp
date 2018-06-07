#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e6 + 5;
ll ans, a[maxn], n, k, L[60], R[60];

void getL(ll u){
    memset(L, 0, sizeof(L));
    ll tmp = 1; L[tmp] = u;
    for(ll i = u - 1; i >= 1; i--){
        if(a[i] < a[u]) L[tmp] = i;
        else L[++tmp] = i;
        if(tmp > 51) break;
    }
}

void getR(ll u){
    memset(R, 0, sizeof(R));
    ll tmp = 1; R[tmp] = u;
    for(ll i = u + 1; i <= n; i++){
        if(a[i] < a[u]) R[tmp] = i;
        else R[++tmp] = i;
        if(tmp > 51) break;
    }
}

void solve(){
    scanf("%lld%lld", &n, &k);
    for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(ll i = 1; i <= n; i++){
        getL(i);
        getR(i);
        for(ll j = 1; j <= 50 && L[j]; j++){
            for(ll p = 1; p <= 50 && R[p]; p++){
                if(j + p - 2 < k){
                    ll tmp1 = L[j - 1], tmp2 = R[p - 1];
                    if(tmp1 == 0) tmp1 = i + 1;
                    if(tmp2 == 0) tmp2 = i - 1;
                    ans += (ll) (tmp1 - L[j]) * (R[p] - tmp2) * a[i];
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    solve();
    return 0;
}
