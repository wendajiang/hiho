#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int A[maxn];
int n;

void solve(){
    map<int, int> cnt;
    set<pair<int, int>> S;
    for(int i = 0; i < n; i++){
        cnt[A[i]]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++) S.insert(make_pair(it->second, it->first));
    if((--S.end())->first * 2 - 1 > n){
        printf("-1\n");
        return;
    }
    int x;
    int pre = -1;
    for(int i = 0; i < n; i++){
        if((--S.end())->first * 2 - 1 == (n - i))
            x = (--S.end())->second;
        else{
            auto it = cnt.begin();
            if(it->first == pre) it++;
            x = it->first;
        }
        S.erase(make_pair(cnt[x], x));
        if((--cnt[x]) > 0){
            S.insert(make_pair(cnt[x], x));
        }else{
            cnt.erase(x);
        }
        printf("%d ", x);
        pre = x;
    }
    printf("\n");
}
int main(){
    while(scanf("%d", &n) == 1 && n){
        for(int i = 0; i < n; i++) cin >> A[i];
        solve();
    }
    return 0;
}


