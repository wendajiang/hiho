 #include "include.h"
//#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int N, K;
int a[maxn];
int b[10 + 3];

struct Data{
    int a, b;
    double res;
    bool operator < (const Data & rhs) const{
        double deltal = log(float(a + 1)) / b - res;
        double deltar = log(float(rhs.a + 1)) / rhs.b - rhs.res;
        return deltal < deltar;
    }
};

void solve(){
    while(scanf("%d%d", &N, &K) == 2 && K){
        for(int i = 0; i < K; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < K; i++){
            scanf("%d", &b[i]);
        }
        priority_queue<Data> pq;
        for(int i = 0; i < K; i++){
            Data tmp;
            tmp.a = a[i];
            tmp.b = b[i];
            tmp.res = double(log(float(tmp.a))) / tmp.b;
            pq.push(tmp);
        }
        while(N--){
            Data tmp = pq.top();
            pq.pop();
            tmp.a = tmp.a + 1;
            tmp.res = double(log(float(tmp.a))) / tmp.b;
            pq.push(tmp);
        }
        double res = 1;
        int count = 1;
        while(!pq.empty()){
            Data tmp = pq.top(); pq.pop();
            if((count++) % 5 == 0) res += 0.03;
            // cout << tmp.a << " " << tmp.b << endl;
            res *= pow(double(tmp.a), double(1.0) / tmp.b);
        }
        cout << fixed << setprecision(5) << res << endl;
        printf("%.5f\n", res);
    }
}

int main(){
    solve();
    return 0;
}

