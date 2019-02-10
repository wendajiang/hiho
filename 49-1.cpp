#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

map<int, char> i2c;
map<char, int> c2i;
int diff[] = {-1, 0, 1};
void init(){
    for(int i = 0; i <= 9; i++){
        i2c.insert(make_pair(i, i + '0'));
        c2i.insert(make_pair(i + '0', i));
    }
    for(int i = 0; i <= 5; i++){
        i2c.insert(make_pair(i + 10, i + 'a'));
        c2i.insert(make_pair(i + 'a', i + 10));
    }
        
}

int getans(int ten, int one, int ten2){
    return abs(ten * 16 + one - ten2 * 16 - ten2);
}

int main(){
    string buff;
    cin >> buff;
    if(buff.size() != 7) return 0;
    string res;
    res += "#";
    init();
    for(int i = 1; i <= 6; i+=2){
        int ten = c2i[buff.at(i)];
        int one = c2i[buff.at(i + 1)];
        int ans = 0;
        int Min = INT_MAX;
        for(int i = 0; i < 3; i++){
            if(Min > getans(ten, one, ten + diff[i])){
                Min = getans(ten, one, ten + diff[i]);
                ans = i;
            }
        }
        res += i2c[ten + diff[ans]];
        
    }
    cout << res << endl;

    return 0;
}
