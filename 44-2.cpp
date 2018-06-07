#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 10010;

int K, len;
string ss;
bool w[maxn];

int getnums(int x, int y){
    int re = 3;
    while(x){ x /= 10; re++ ;}
    while(y){ y /= 10; re++; }
    return re;
}

bool check(int nr){
    int now = 0, tmp, k = 0;
    while(1){
        if(k == nr) return 0;
        tmp = now + K - getnums(++k, nr) - 1;
//        if(tmp <= now) return 0;
        if(tmp > len)
            tmp = len - 1;
        while(!w[tmp]){
//            if(tmp == now) return 0;
            tmp--;
        }now = tmp + 1;
        if(now == len) break;
    }
    return 1;
}

int sbsearch(){
    for(int i = 1; i < len; i++){
        if(check(i)) return i;
    }
    return len;
}

int main(){
    while(cin >> K){
        memset(w, 0, sizeof(w));
        getline(cin, ss);
        getline(cin, ss);
        len = ss.size();
        w[len - 1] = 1;
        for(int i = 0; i < len - 1; i++){
            if(ss[i] == ' ' || ss[i + 1] == ' ')
                w[i] = 1;
        }
        int nr = sbsearch();
        int now = 0, count = 0;
        while(1){
            int pos = now + K - getnums(++count, nr) - 1;
            if(pos >= len)
                pos = len - 1;
            while(!w[pos]){
                pos--;
            }
            for(int i = now; i <= pos; i++) printf("%c", ss[i]);
            printf("(%d/%d)\n", count, nr);
            now = pos + 1;
            if(now == len) break;
        }

    }
    return 0;
}