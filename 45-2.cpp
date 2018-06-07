#include "include.h"
// #include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 5;

int x[maxn], y[maxn];
double k , b;
int n;

bool is_ok(int i, int j, int kase){ // kase 1: 竖线， 2: 横线: 3: 正常
    if(kase == 3){
        bool ok = true;
        for(int i1 = 1; i1 <= n; i1 ++){
            if(i1 != i && i1 != j && k * x[i1] + b - y[i1] > 0){
                ok = false;
            }
        }
        return ok;
    }else if(kase == 1){
        bool ok = true;
        for(int i1 = 1; i1 <= n; i1 ++){
            if(i1 != i && i1 != j && x[i1] > x[i]){
                ok = false;
            }
        }
        return true;
        
    }else{
        bool ok = true;
        for(int i1 = 1; i1 <= n; i1 ++){
            if(i1 != i && i1 != j && y[i1] > y[i]){
                ok = false;
            }
        }
        return true;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(x[j] == x[i]){
                if(is_ok(i, j, 1)) {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }else if(y[j] == y[i]){
                if(is_ok(i, j, 2)) {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }else{
                k = (float)(y[j] - y[i]) / (x[j] - x[i]);
                b = (float)(y[i]*x[j] - x[i]*y[j]) / (x[j] - x[i]);
                if(is_ok(i, j, 3)){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}