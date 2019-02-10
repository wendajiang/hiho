#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
const int base = 'a';

struct Trie{
    bool isWord;
    struct Trie* son[26];
    int num; 
    Trie(): isWord(false), num(0) {
        for(int i = 0; i < 26; i++){
            son[i] = NULL;
        }
    }
};

Trie* Insert(string s, Trie* root){
    if(root == nullptr){
        root = new Trie;
    }
    Trie* cur = root;
    for(int i = 0; i < s.size(); i++){
        if(cur->son[s[i] - base] == NULL){
            cur->son[s[i] - base] = new Trie;
            cur->son[s[i] - base]->num ++;
            cur = cur->son[s[i] - base];
        }else{
            cur->son[s[i] - base]->num ++;
            cur = cur->son[s[i] - base];
        }
    }
    cur->isWord = true;
    return root;
}
int Search(string s, Trie* root){
    Trie* cur = root;
    for(int i = 0; i < s.size(); i++){
        if(cur->son[s[i] - base] == NULL){
            return 0;
        }else{
            cur = cur->son[s[i] - base];
        }
    }
    return cur->num;
}


int main(){
    int n, m;
    string buff;
    Trie* root = NULL;
    scanf("%d", &n);
    while(n --){
        cin >> buff;
        root = Insert(buff, root);
    }
    scanf("%d", &m);
    while(m --){
        cin >> buff;
        int ans = Search(buff, root);
        cout << ans << endl;
    }
    return 0;
}
