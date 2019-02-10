#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

struct Frac{
    int x, y;
    Frac(int a, int b) : x(a), y(b) {}
    bool operator < (const Frac& rhs) const{
        return double(x) / y > double(rhs.x) / rhs.y;
    }
};



int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) == 2){
        priority_queue<Frac> pq;
        for(int i = 0; i < n; i++){
            int p; cin >> p;
            pq.push(Frac(1, p));
        }
        while(--k){
            Frac e = pq.top();
            pq.pop();
            if(e.x + 1 < e.y){
                pq.push(Frac(e.x + 1, e.y));
            }
        }
        printf("%d\/%d\n", pq.top().x, pq.top().y);
    }
    return 0;
}
