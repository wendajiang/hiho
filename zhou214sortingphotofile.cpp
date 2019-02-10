/*************************************************************************
	> File Name: zhou214sortingphotofile.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/ 7 00:11:46 2018
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void test() {
    string cc{"bejing"};
    int i = 0;
    for (i =0 ; i < cc.size(); i++) {
        if(!isalpha(cc[i])) {
            break;
        }
    }
    cout << atoi(cc.substr(i).c_str()) << endl;
}

void hh() {
        int n;
    cin >> n;
    vector<string> ss;
    for (int i = 0 ; i < n; i++) {
        string tmp;
        cin >> tmp;
        ss.push_back(tmp);
    }
    sort(ss.begin(), ss.end(), [](string& a, string& b) {
        int ia = 0, ib = 0;
        for (; ia < a.size(); ia++) {
            if (!isalpha(a[ia])) {
                break;
            }
        }

        for (; ib < b.size(); ib ++) {
            if (!isalpha(b[ib])) {
                break;
            }
        }
        string astr = a.substr(0, ia);
        int anum = atoi(a.substr(ia).c_str());
        string bstr = b.substr(0, ib);
        int bnum = atoi(b.substr(ib).c_str());
        if (astr != bstr) {
            return astr < bstr;
        } else {
            return anum < bnum;
        }
    });

    for (int i = 0; i < ss.size(); i++) {
        cout << ss[i] << endl;
    }
}

int main() {

    // test();
    hh();
    return 0;
}

