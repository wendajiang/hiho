//
// Created by JohnJD on 2019-08-13.
//

#include <bits/stdc++.h>
using namespace std;

int M, N, L;

const int MAXN = 1e5 + 10;

int A[MAXN];
int B[MAXN];
int C[MAXN];

long long D = LONG_MAX;

void test(long long x,long long y,long long z)
{
    long long d = abs(x - y) + abs(y - z) + abs(z - x);
    if (d < D)
    {
        D = d;
    }
}

void solve(){
    scanf("%d%d%d", &M, &N, &L);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 1; i <= L; i++) {
        scanf("%d", &C[i]);
    }
    A[0] = B[0] = C[0] = -1e9;
    A[M + 1] = B[N + 1] = C[L + 1] = 1e9;   // 1e7 是不够的 
    sort(A, A + M + 1);
    sort(B, B + N + 1);
    sort(C, C + L + 1);

    int ibl = 0, ibr = 0, icl = 0, icr = 0;
    for (int i = 1; i <= M; i++) {
        int curA = A[i];
        while(B[ibl + 1] < curA) ibl++;

        while(C[icl + 1] < curA) icl++;
        test(curA, B[ibl], C[icl]);
        test(curA, B[ibl], C[icl + 1]);
        test(curA, B[ibl + 1], C[icl]);
        test(curA, B[ibl + 1], C[icl + 1]);


    }
    printf("%lld\n", D);
}


int main() {
    solve();
    return 0;
}
