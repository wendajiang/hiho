#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;

    scanf("%lld", &N);
    N <<= 1;
    long long sum = (1 + N) * N / 2;

    cout <<  (sum / 2 - 1 + N - 1) << endl; //因为足够机智，所以Ho奇数是会选小的，所以3的时候只有14，不会为15

    return 0;
}
