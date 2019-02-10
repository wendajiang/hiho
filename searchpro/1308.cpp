#include "../include.h"
// #include <bits/stdc++.h>
using namespace std;

int T;
map<char, int> c2o;
char knight[3][2];
int dx[] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dy[] = {-2, -1, 2, 1, -2, -1, 2, 1};
int step[3][8][8];

void init(){
    memset(step, -1, sizeof(step));
    for(int i = 0; i < 8; i++){
        c2o.insert(make_pair('A' + i, i));
        c2o.insert(make_pair('1' + i, i));
    }
}

bool checkState(int nextX, int nextY){
    if(nextX < 0 || nextX > 7 || nextY < 0 || nextY > 7) return false;
    else return true;
}

void bfs_solve(int f[8][8], int x, int y){
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    f[x][y] = 0;
    while(!Q.empty()){
        pair<int, int> nowState = Q.front(); Q.pop();
        int nowX = nowState.first, nowY = nowState.second;
        for(int i = 0; i < 8; i++){
            int nextX = nowX + dx[i], nextY = nowY + dy[i];
            if(checkState(nextX, nextY) && f[nextX][nextY] == -1){
                f[nextX][nextY] = f[nowX][nowY] + 1;
                Q.push(make_pair(nextX, nextY));
            }
        }
    }
}

void solve(){
    init();
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 3; i++){
            scanf("%s", knight[i]);
        }
        memset(step, -1, sizeof(step));
        for(int i = 0; i < 3; i++){
            bfs_solve(step[i], c2o[knight[i][0]], c2o[knight[i][1]]);
        }
        int ans = INT_MAX;
        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
                int sum = 0;
                for(int i = 0; i < 3; i++)
                    sum += step[i][x][y];
                if(ans > sum) ans = sum;
            }
        }
        cout << ans << endl;
    }
}

int main(){
    solve();
    return 0;
}
