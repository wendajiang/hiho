#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
class node{
public:
    bool isWord;
    node *next[26];
    node *pre;
    node(){
        isWord = false;
        pre = NULL;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class trie{
public:
    trie(){
        root = new node();
    }
    void in(string &s){
        node* cur = root;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(!cur->next[s.at(i) - base])
                cur->next[s.at(i) - base] = new node();
            cur = cur->next[s.at(i) - base];
        }
        cur->isWord = true;
    }

    //失配才会出现找fail
    void build(){
        queue<node*> Q;
        node *cur = root;
        for(int i = 0; i < 26; i++){
            if(cur->next[i]){
                cur->next[i]->pre = root;
                Q.push(cur->next[i]);
            }
        }
        while(!Q.empty()){
            cur = Q.front();
            Q.pop();
            for(int i = 0; i < 26; i++){
                node *p = cur->next[i];
                if(p && !p->isWord){
                    node* pre = cur->pre;
                    while(pre){
                        if(pre->next[i]){
                            p->pre = pre->next[i];
                            if(p->pre->isWord)
                                p->isWord = true;
                            break;
                        }else
                            pre = pre->pre;
                    }
                    if(p->pre == NULL)
                        p->pre = root;
                    Q.push(p);
                }
            }
        }
    }
    bool search(string &s){
        int l = s.size();
        node* cur = root;
        for(int i = 0; i < l; i++){
            while(true){
                if(cur->next[s.at(i) - base]){
                    cur = cur->next[s.at(i) - base];
                    if(cur->isWord)
                        return true;
                    break;
                }else{
                    cur = cur->pre;
                }
                if(cur == root || cur == NULL){
                    cur = root;
                    break;
                }
            }
        }
        return false;
    }
private:
    node* root;
    const char base = 'a';
};

int main(){
    int N;
    trie T;
    scanf("%d", &N);
    string buff;
    for(int i = 0; i < N; i++){
        cin >> buff;
        T.in(buff);
    }
    T.build();
    cin >> buff;
    bool ans = T.search(buff);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
