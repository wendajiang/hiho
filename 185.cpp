#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
//都是由1开始

//卡在了可能多次询问,因为想节省空间把图的信息改了,还是要加一个vis数组表示是否遍历过某个点

const int maxn = 500 + 5;

struct Node{
    int x, y, dist;
    bool operator < (const Node& rhs) const{
        return rhs.dist < dist;
    }
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int Bx[maxn];
int Ay[maxn];
int K;
int N, M;
int Q;
int x, y, p, q;
int G[maxn][maxn];
int vis[maxn][maxn];
int dist[maxn][maxn];

void _init(){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            dist[i][j] = INT_MAX;

}

void solve(int x, int y, int p, int q){
    _init();
//    memset(dist, 1, sizeof(dist));
    // memset(vis, 0, sizeof(vis));
    priority_queue<Node> pq;
    Node u;
    u.x = x;
    u.y = y;
    u.dist = 0;
    dist[x][y] = 0;
    // vis[x][y] = 1;
    pq.push(u);
    while(!pq.empty()){
        Node u = pq.top(); pq.pop();
        vis[u.x][u.y] = 1;
        if(u.x == p && u.y == q){
            cout << dist[p][q] << endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            if(u.x + dx[i] >= 1 && u.x + dx[i] <= N && u.y + dy[i] >= 1 && u.y + dy[i] <= M && G[u.x + dx[i]][u.y + dy[i]] == 0){
                if(vis[u.x+dx[i]][u.y+ dy[i]] == 0)
                if(dist[u.x + dx[i]][u.y + dy[i]] > u.dist + ((dx[i] == 0) ? Ay[max(u.y, u.y + dy[i]) - 1] : Bx[max(u.x, u.x + dx[i]) - 1])){
                    dist[u.x + dx[i]][u.y + dy[i]] =
                     u.dist + ((dx[i] == 0) ? Ay[max(u.y, u.y + dy[i]) - 1] : Bx[max(u.x, u.x + dx[i]) - 1]);
                     Node v;
                     v.x = u.x + dx[i];
                     v.y = u.y + dy[i];
                     v.dist = dist[v.x][v.y];
                     pq.push(v);
                }

            }
        }
    }
    cout << -1 << endl;

}


int main(){
    while(cin >> N >> M){
        memset(G, 0, sizeof(G));
        for(int i = 1; i < N; i++){
            cin >> Bx[i];
        }
        for(int i = 1; i < M; i++){
            cin >> Ay[i];
        }
        cin >> K;
        int tmpx, tmpy;
        for(int i = 0; i < K; i++){
            cin >> tmpx >> tmpy;
            G[tmpx][tmpy] = 1;
        }
        cin >> Q;
        for(int i = 0; i < Q; i++){
            cin >> x >> y >> p >> q;
            solve(x, y, p, q);
        }
    }
    return 0;
}

