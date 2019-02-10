#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int N;
int a[maxn];
int T[maxn];
long long  ans = 0;
long long p[32][2];


void mergeSort(int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        map<int, int> bits;
        for(int i = l; i <= mid; i++){
            int bit = 0;
            int val = a[i];
            while(val){
                if(val & 1) bits[bit]++;
                val >>= 1;
                bit++;
            }
        }
        int x = l, y = mid + 1, cur = 0;
        while(x <= mid && y <= r){
            if(a[x] <= a[y]){
                T[cur++] = a[x];
                int val = a[x];
                int bit = 0;
                while(val){
                    if(val & 1) bits[bit]--;
                    val >>= 1;
                    bit ++;
                }
                x++;
            }else{
                T[cur++] = a[y];
                int val = a[y], al = mid - x + 1;
                for(int i = 0; i < 20; i++){
                    if(val & (1 << i)){
                        ans += (al - bits[i]) * (1 << i);
                    }else{
                        ans += bits[i] * (1 << i);
                    }
                }
                y++;
            }
        }
        while(x <= mid) T[cur++] = a[x++];
        while(y <= r) T[cur++] = a[y++];
        for(int i = l; i <= r; i++) a[i] = T[i - l];
    }
}

int main(){
    while(scanf("%d", &N) == 1 && N){
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        memset(T, 0, sizeof(T));
        ans = 0;
        mergeSort(0, N - 1);
        // cout << ans << endl;
        // for(auto p : tmpans){
        //     cout << p.first << " " << p.second << endl;
        // }
        cout << ans << endl;
    }
    return 0;
}
