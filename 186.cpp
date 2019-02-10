#include "include.h"
// #include <bits/stdc++.h>

using namespace std;

//typedef long long ll;

//模拟写字过程，TLE超时，要判断循环的样子

const int maxn = 1000000000 + 5;

int N, M;
char ch[maxn];
int w[maxn];

int main(){

    scanf("%d %d\n", &N, &M);
    fgets(ch, maxn, stdin);
    int len = strlen(ch) - 1;
//    memset(ch, 0, sizeof(ch));
    memset(w, 0, sizeof(w));
    w[len - 1] = 1;
    for(int i = 0; i < len - 1; i++){
        if(ch[i] == ' ' || ch[i + 1] == ' '){
            w[i] = 1;
        }
    }
    int row = 0, column = 0;
    int cur = 0;
    while(N--){
        cur = 0;
        int end = cur + (M - column) - 1;
        while(!w[end]) end--;
        column = end - cur + 1 + M - column;
        cur = end + 1;
        row += 1;
        while(cur < len){
            end = cur + M - 1;
            while(!w[end]) end --;
            column = end - cur + 1;
            cur = end + 1;
            if(cur == len && N == 0) continue;
            else row += 1;
        }
    }

    cout << row << " " << column << endl;

    return 0;
}