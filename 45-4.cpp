#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
const int maxm = 100000 + 5;

int n, m;

struct Edge{
    int from, to;
    Edge(int from, int to): from(from), to(to) {}
};

vector<Edge> edges;

vector<int> G[maxn];


void addEdge(int small, int big){
    edges.push_back(Edge(small, big));
    int idx = edges.size() - 1;
    G[small].push_back(idx);
}



void dfs(int s, int t, bool *visited){
    visited[s] = 1;
    if(s == t){
        return;
    }
    for(int i = 0; i < G[s].size(); i++){
        int idx = G[s][i];
        Edge e = edges[idx];
        int v = e.to;
        if(!visited[v])
            dfs(v, t, visited);
    }


}

int main(){
    scanf("%d %d\n", &n, &m);
    int small, big;
    char alg;
    bool vis1[maxn], visn[maxn];
    memset(vis1, 0, sizeof(vis1));
    memset(visn, 0, sizeof(visn));
    vis1[1] = true; visn[n] = true;
    for(int i = 0; i < m; i++){
        scanf("A%d %c A%d\n", &small, &alg, &big);
        addEdge(small, big);
        if(alg == '='){
            addEdge(big, small);
            if(vis1[big]){
                dfs(big, n, vis1);
                if(vis1[n]) { cout << i + 1 << endl; return 0; }
            }
            if(visn[big]){
                dfs(big, 1, visn);
                if(visn[1]) {cout << i + 1 << endl; return 0; }
            }
        }
        if(vis1[small]) {
            dfs(small, n, vis1);
            if(vis1[n]) {cout << i + 1 << endl; return  0; }
        }
        if(visn[small]) {
            dfs(small, 1, visn);
            if(visn[1]) { cout << i + 1 << endl; return 0;}
        }
        
    }
    cout << -1 << endl;
    return 0;
}