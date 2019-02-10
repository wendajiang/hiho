#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    vector<string> mm;
    mm.push_back("January");
    mm.push_back("February");
    mm.push_back("March");
    mm.push_back("April");
    mm.push_back("May");
    mm.push_back("June");
    mm.push_back("July");
    mm.push_back("August");
    mm.push_back("September");
    mm.push_back("October");
    mm.push_back("November");
    mm.push_back("December");
    
    for (int i = 0; i < T; i++) {
        string m, d, y;
        cin >> m >> d >> y;
        auto st = find(mm.begin(), mm.end(), m);
        int sm = st - mm.begin() + 1;
        int sd = atoi(d.substr(0, d.size() - 1).c_str());
        int sy = atoi(y.c_str());
        cin >> m >> d >> y;
        auto tt = find(mm.begin(), mm.end(), m);
        int tm = tt - mm.begin() + 1;
        int td = atoi(d.substr(0, d.size() - 1).c_str());
        int ty = atoi(y.c_str());
        if (sm < 2 || (sm == 2 && sd <= 29)) sy--;
        if (tm < 2 || (tm == 2 && td < 29)) ty--;
        int cnt1 = ty / 400 - sy / 400;
        int cnt2 = ty / 4 - sy / 4 - (ty / 100 - sy / 100);
        printf("Case #%d: %d\n", i + 1, cnt2 + cnt1);
    }
    return 0;
}
