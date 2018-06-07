#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100 + 5;

char matrix[maxn][maxn];
int N;

const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int solve(int i, int j){
    int count = 0;
    for(int k = 0; k < 8; k++){
        if(i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < N
           && matrix[i + dx[k]][j + dy[k]] == '*')
            count ++;

    }
    return count;
}

int main(){

    
    while(scanf("%d", &N) == 1 && N){
        memset(matrix, 0, sizeof(matrix));
        char buff[maxn];
        for(int i = 0; i < N; i++){
            scanf("%s", buff);
            for(int j = 0; j < N; j++){
                matrix[i][j] = buff[j];
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j] == '.'){
                    int x = solve(i, j);
                    matrix[i][j] = '0' + x;
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}