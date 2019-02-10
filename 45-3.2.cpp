#include "include.h"
// #include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int lens = s.size();
    int lent = t.size();
    if(lens != lent){
        cout << -1 << endl;
    }
    int count = 0;
    for(int i = 0; i < lens; i++){
        if(s[i] == t[i]) continue;
        if(s[i] == '_' && t[i] == 'L'){
            int tmp = i + 1;
            while(tmp < lens && s[tmp] != 'L') tmp++;
            if(tmp == lens) {
                count = -1;
                break;
            }
            s[i] = 'L';
            s[tmp] = '_';
            count += tmp - i;
        }else if(s[i] == 'R' && t[i] == '_'){
            int tmp = i + 1;
            while(tmp < lens && s[tmp] != '_') tmp ++;
            if(tmp == lens){
                count = -1;
                break;
            }
            s[i] = '_';
            s[tmp] = 'R';
            count += tmp - i;
        }else{
            count = -1;
            break;
        }
    }
    cout << count << endl;
}