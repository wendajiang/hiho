#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int maxp = 1e5 + 5;
int Next[maxp];

void getNext(const string &p){
    Next[0] = -1;
    int i = -1;
    int j = 0;
    while(j < p.size()){
        if(i == -1 || p.at(i) == p.at(j)){
            i++;
            j++;
            if(j == p.size() || p.at(i) != p.at(j)){
                Next[j] = i;
            }else{
                Next[j] = Next[i];
            }
        }else{
            i = Next[i];
        }
    }
}

int kmpSearch(const string &s, const string &p){
    getNext(p);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < s.size()){
        if(j == -1 || s.at(i) == p.at(j)){
            i++;
            j++;
        }else if(j < p.size())
            j = Next[j];
        if(j == p.size()){
            count ++;
            j = Next[j];
        }
    }
    return count;
}
int main(){
    int N;
    scanf("%d", &N);
    while(N --){
        string s, p;
        cin >> p;
        cin >> s;
        int ans = kmpSearch(s, p);
        cout << ans << endl;
    }
    return 0;
}
