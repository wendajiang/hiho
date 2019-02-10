#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 1e3 + 1;


int main(){
    long long ans = LLONG_MAX;
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> point;
    map<pair<int, int>, int> p_mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        point.push_back(make_pair(x, y));
        p_mp[make_pair(x, y)] = 1;
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (point[i].second == point[j].second) continue;
            if (point[i].first == point[j].first) continue;

            if (p_mp[make_pair(point[i].first, point[j].second)] && 
                p_mp[make_pair(point[j].first, point[i].second)]) {
                    ans = min(ans, 1LL * abs(point[i].second - point[j].second) *
                                abs(point[i].first - point[j].first));
                    flag = true;
                }
        }
    }
    if (flag) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}
