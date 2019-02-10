#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
const int MAXK = 1e5 + 1;

int d[MAXN];
int N, K;

bool check(int t) {
    if (t > K) return false;
    long long hoCup = t;
    int iCnt = 0;
    int oCnt = 0;
    for (int i = 0; i < N; i++) {
        if (hoCup <= d[i]) {
            iCnt++;
            hoCup = t;
        } else {
            oCnt++;
            hoCup -= d[i];
            hoCup += t;
        }
    }
    if (oCnt > iCnt) return true;
    else return false;
}

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }

    int l = 0, r = K + 1;
    int mid = (l + r) / 2;
    while(l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
