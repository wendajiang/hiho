#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
typedef long long ll;
struct frac{
    ll a, b;
};

bool cmp(frac& x, frac &y){
    return (x.a * y.b) < (y.a * x.b);
}

int n, k, p[maxn], tot;

frac a[100000 * 100];

int main(){
    cin >> n >> k;
    tot = 0;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        for(int j = 1; j < p; j++){
            a[tot].a = j; a[tot].b = p;
            tot++;
        }
    }
    sort(a, a + tot, cmp);
    cout << a[k - 1].a << '/' << a[k - 1].b << endl;
    return 0;
} 