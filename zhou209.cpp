#include <bits/stdc++.h>
using namespace std;
map<int, int> f;

int cal(int n){
    if(f.end() == f.find(n)) {
        int s;
        if(n % 2 == 0) s = cal(n / 2);
        else if(n == 1) s = 1;
        else s = min(cal(n - 1), cal(n + 1)) + 1;
        f[n] = s;
    }
    return f[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int res = cal(n);
    printf("%d\n", res);
    return 0;
}
