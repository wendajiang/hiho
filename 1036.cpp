#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Hash(x) (x - 'a')

const int N = 1e6 + 1, CH = 26;
struct Trie{
    Trie *next[CH];
    Trie *fail;
    int len;
    Trie(): len(0), fail(NULL) {
        for (int i = 0; i < CH; i++) {
            next[i] = NULL;
        }
    }
};

vector<pair<int, int>> LR;

char str[N];

class ACauto{

public:
    void init(){
        root = new Trie();
    }

    void insert(char *s){
        Trie *p = root;
        int i;
        for(i = 0; s[i]; i++){
            int c = Hash(s[i]);
            if(p -> next[c] == NULL){
                p->next[c] = new Trie();
            }
            p = p -> next[c];
        }
        p -> len = i;

    }

    void build(){
        queue<Trie *> q;
        q.push(root);
        root -> fail = NULL;
        while(!q.empty()){
            Trie *now = q.front();
            q.pop();
            for(int i = 0; i < CH; i++){
                Trie *son = now -> next[i];
                Trie *tp = (now == root)? root: now -> fail->next[i];
                if(son == NULL){
                    now -> next[i] = tp;
                }else{
                    son -> fail = tp;
                    q.push(son);
                }
            }
        }
    }

    //两种不同的build，query相同可以
    void build2() {
        queue<Trie* > q;
        q.push(root);
        root->fail = NULL;
        while(!q.empty()) {
            Trie* now = q.front();
            q.pop();
            for (int i = 0; i < CH; i++) {
                if (now->next[i] != NULL) {
                    if (now == root) now->next[i]->fail = root;
                    else {
                        Trie* p = now->fail;
                        while(p != NULL) {
                            if (p->next[i] != NULL) {
                                now->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if (p == NULL) now->next[i]->fail = root;
                    }
                    q.push(now->next[i]);
                }
            }
        }
    }


    bool query(char* s) {
        Trie *now = root;
        for (int i = 0; s[i]; i++) {
            int c = Hash(s[i]);
            if (now->next[c] != NULL) {
                now = now->next[c];
                if (now->len) {
                    return true;
                }
            } else {
                Trie* p = now->fail;
                while (p && p->next[c] == NULL) p = p->fail;
                if (p == NULL) now = root;
                else now = p->next[c];
            }
        }
        return false;
    }

    void query2(char *s) {
        Trie *now = root;
        for (int i = 0; s[i]; i++) {
            int c = Hash(s[i]);
            if (now->next[c] != NULL) {
                now = now->next[c];
                if (now->len) {
                    pair<int, int> tmp;
                    tmp.first = i - now->len + 1;
                    tmp.second = i;
                    LR.push_back(tmp);
                }
            } else {
                Trie* p = now->fail;
                while (p && p->next[c] == NULL) p = p->fail;
                if (p == NULL) now = root;
                else now = p->next[c];
            }
        }
    }

private:
    Trie* root;
}ac;

int main() {
    int n;
    scanf("%d", &n);
    ac.init();
    for (int i = 0; i < n; i++) {

        scanf("%s", str);
        ac.insert(str);
    }
    ac.build();
    scanf("%s", str);

    ac.query2(str);
    for (int i = 0; i < LR.size(); i++) {
        cout << LR[i].first << " " << LR[i].second << endl;
    }
    if (ac.query(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
