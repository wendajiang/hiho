#include <bits/stdc++.h>
using namespace std;

map<int, int> father;
map<int, int> ranks;

int find(int u) {
    return father[u] = (father[u] == u ? u : find(father[u]));
}

void Uion(int u, int v) {
    int f1 = find(u), f2 = find(v);
    if (ranks[f1] < ranks[f2]) {
        father[f1] = f2;
    } else {
        father[f2] = f1;
        if (ranks[f1] == ranks[f2]) {
            ranks[f1] ++;
        }
    }
}

int main(){

    return 0;
}
