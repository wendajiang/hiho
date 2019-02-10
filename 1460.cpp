#include <bits/stdc++.h>
using namespace std;

void hh() {
    int k; cin >> k;
    string s, r = ""; cin >> s;
    vector<int> index[26];
    for (int i = 0; i < s.size(); i++) {
        index[s[i] - 'a'].push_back(i);
    }
    int p = -1; // 当前位置

    while(k) {
        bool status = false;
        for (int i = 0; i < 26; i++) {
            auto pp = upper_bound(index[i].begin(), index[i].end(), p);
            if (pp == index[i].end()) continue;
            if (s.size() - *pp >= k) { //可以使用
                r += char('a' + i);
                k--;
                p = *pp;
                status = true;
            }
            if (status) break;
        }
        if (!status) break;
    }
    cout << r << endl;
}

int main(){
    hh();
    return 0;
}
