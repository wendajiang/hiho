#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

int main(){
    string word;
    cin >> word;
    set<char> bag;
    int len = word.size();
    string res;
    for(int i = 0; i < len; i++){
        if(word[i] == 'J') word[i] = 'I';
        if(!bag.count(word[i])){
            res += word[i];
            bag.insert(word[i]);
        }
    }
    for(int i = 0; i < 26; i++){
        if(!bag.count('A' + i) && 'A' + i != 'J'){
            res += 'A' + i;
        }
    }
    for(int i = 0; i < 25; i++){
        if(i != 0 && (i % 5 == 0)) printf("\n");
        printf("%c", res.at(i));
    }
    printf("\n");
    return 0;
}
