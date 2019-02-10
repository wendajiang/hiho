#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

typedef long long ll;
ll n, k, p[maxn];

ll check(int x, int idx){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll tot = (int)(x * p[i] / p[idx]);
        sum += tot;
    }
    return sum;
}

int main(){
    while(scanf("%lld%lld", &n, &k) == 2){
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n; i++){
            ll l = 1, r = p[i] - 1;
            while(l < r){
                ll mid = l + (r - l) / 2;
                if(check(mid, i) >= k) r = mid;
                else l = mid + 1;
            }
            if(check(r, i) == k){
                printf("%lld\/%lld\n", r, p[i]);
                break;
            }
        }
    }
    return 0;
}