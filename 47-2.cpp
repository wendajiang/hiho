#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-10;

int p[3];
int v[3];

struct Ship{
    int a, b, c, d;
    bool hit;
}s[3];

void solve(){
    int T;
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 3; i++){
            scanf("%d%d", &p[i], &v[i]);
        }
        int count = 0;
        for(int i = 0; i < 3; i ++){
            scanf("%d%d%d%d", &s[i].a, &s[i].b, &s[i].c, &s[i].d);
            s[i].hit = false;
        }
        bool hit[3] = {0};
        int ans = 0;
        for(int ti = 0; ti < 260010; ti++){
            double t = 1.0 * ti / 1300;
            for(int i = 0; i < 3; i++){
                if(hit[i]) continue;
                double x = t * v[i] * cos(PI * p[i] / 180);
                double y = t * v[i] * sin(PI * p[i] / 180);
                for(int j = 0; j < 3; j++){
                    if(s[j].hit) continue;
                    if(x - s[j].a > -eps && s[j].c - x > -eps && 
                      y - s[j].d > -eps && s[j].b - y > -eps){
                          hit[i] = true;
                          s[j].hit = true;
                          ans ++;
                          break;
                      }
                }
            }
            if(ans == 3 ) break;
        }
        printf("%d\n", ans);

    }
}
int main(){
    solve();
    return 0;
}
