#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int N;
int a[maxn];
int T[maxn];
long long  ans = 0;


int main(){
    while(scanf("%d", &N) == 1 && N){
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        ans = 0;
        for(int i = 0; i < N - 1; i++){
            for(int j = i + 1; j < N; j++){
                if(a[i] > a[j]){
                    ans += (a[i] ^ a[j]);
                }
            }
        }
        cout << ans << endl;
    }
    

    return 0;
}
