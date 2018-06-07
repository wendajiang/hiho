#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int maxn = 10 + 5;
long long a, b;
int n;
int main(){
    while(scanf("%d%lld%lld", &n, &a, &b) == 3){
        vector<int> ss,tt, index;
        for(int i = 0; i < n; i++){
            ss.push_back(a % 10);
            tt.push_back(b % 10);
            index.push_back(i);
            a /= 10;
            b /= 10;
        }

        int ans = INT_MAX;

        do {
            int count = 0;
            vector<int> tmp, pos(n);
            tmp = index;
            for(int i = 0; i < n; i++) pos[tmp[i]] = i;
            for(int i = 0; i < n; i++){
                if(tmp[i] != i){
                    pos[tmp[i]] = pos[i];
                    swap(tmp[pos[i]], tmp[i]);
                    count++;
                }
            }
            for(int i = 0; i < n; i++) assert(tmp[i] == i);
            for(int i = 0; i < n; i++){
                count = count + min(abs(ss[index[i]] - tt[i]), 10 - abs(ss[index[i]] - tt[i]));
            }
            ans = min(ans, count);
        }while(next_permutation(index.begin(), index.end()));
        cout << ans << endl;
    }
    return 0;
}
