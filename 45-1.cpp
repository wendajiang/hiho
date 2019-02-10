#include "include.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 5;

int x[maxn], y[maxn];
int n;

int d[maxn];

ll ans = 0;
int main(){
    while(scanf("%d", &n) == 1 && n){
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x[i], &y[i]);
        }
        map<ll, ll> count;
        for(int i = 0; i < n; i++){
            d[i] = x[i] - y[i];
            count[d[i]] ++;
        }
        for(auto p : count){
            if(p.first != 0 && count.count(0 - p.first)){
                ll s = count[p.first];
                ll t = count[0 - p.first];
                count[0 - p.first] = 0;
                ans += s * t;
            }else if(p.first == 0){
                ll tmp = p.second;
                if(tmp > 1){
                    ans += tmp * (tmp - 1) / 2;
                }
            }
        }
    
        cout << ans << endl;
    }
    return 0;

}