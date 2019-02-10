#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        string s;
        int K;
        cin >> s >> K;
        int len = s.size();
        if (K * 2 > len) {
            int inter = len - K;
            int cnt = 0;
            for (int i = 0; i < inter; i++) {
                map<char, int> mp;
                int tmp = 0;
                for (int j = 0; i + j * inter < len; j++) {
                    mp[s[i + j * inter]] ++;
                    tmp++;
                }
                int mx = 0;
                for (auto e : mp) {
                    mx = max(e.second, mx);
                }
                cnt += tmp - mx;
            }
            cout << cnt << endl;
        } else {
            int cnt = 0;
            for (int i = 0; i < K; i++) {
                if (s[i] != s[i + len - K]) cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
