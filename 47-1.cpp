#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct tree{
    int w, parent;
    int id;
    set<int> child;
}T[maxn];

void deleteT(int i){
    for(auto x : T[T[i].parent].child){
        if(x == i){ T[T[i].parent].child.erase(x); break;}
    }
    for(auto id : T[i].child){
        T[T[i].parent].child.insert(id);
        T[id].parent = T[i].parent;
    }
    T[i].parent = -1;
}

void solve(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++){
        T[i].id = i;
        scanf("%d", &T[i].w);
    }
    for(int i = 1; i <= N; i++){
        scanf("%d", &T[i].parent);
        T[T[i].parent].child.insert(i);
    }
    for(int i = 1; i <= N; i++){
        if(T[i].w < K){
            deleteT(i);
        }
    }
    cout << T[1].parent;
    for(int i = 2; i <= N; i++){
        cout << " " << T[i].parent;
    }
    cout << endl;
}
int main(){
    solve();
    return 0;
}
