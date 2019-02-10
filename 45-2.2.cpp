#include "include.h"
// #include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 5;

int x[maxn], y[maxn];
int n;

int main(){
    scanf("%d", &n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(x[i] > x[maxx])
            maxx = i;
    }    
    int next_index = 0;
    double k = 0;
    for(int i = 0; i < n; i++){
        if(i == maxx) continue;
        if(x[i] == x[maxx]){
            next_index = i;
            break;
        }
        double tmpk = (double)(y[i] - y[maxx]) / (x[i] - x[maxx]);
        if(tmpk < k){
            k = tmpk;
            next_index = i;
        }
    }
    
    if(maxx < next_index){
        cout << maxx + 1 << " " << next_index + 1 << endl;
    }else
        cout << next_index + 1 << " " << maxx + 1 << endl;
    return 0;

}