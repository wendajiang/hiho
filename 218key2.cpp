#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
#define Hash(x) (x - 'a')

const int N = 500008, CH = 26;
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
                Trie *tp = (now == root)? root: now->fail->next[i];
                if(son == NULL){
                    now -> next[i] = tp;
                }else{
                    son -> fail = tp;
                    q.push(son);
                }
            }
        }
    }

    void query(char *s){
        Trie *now = root;
        for(int i = 0; s[i]; i++){
            int c = Hash(s[i]);
            now = now -> next[c];
            Trie *p = now;
            while(p != root){
                if(p -> len){

                    pair<int, int> tmp;
                    tmp.first = i - p->len + 1;
                    tmp.second = i;
                    LR.push_back(tmp);
                }
                p = p -> fail;
            }

        }
    }


private:
    Trie* root;
}ac;

int main(){
    int n;
    cin >> n;
    ac.init();
    for(int i  = 0; i < n; i++){
        scanf("%s", str);
        ac.insert(str);
    }
    ac.build();
    scanf("%s", str);
    ac.query(str);


    // 合并LR的区间
    sort(LR.begin(), LR.end(), [](pair<int,int>& a, pair<int, int>& b) {
        return a.first < b.first;
    });
    vector<pair<int, int>> nLR;
    for (int i = 0; i < LR.size(); i++) {
        if (i == 0) {
            nLR.push_back(LR[i]);
            continue;
        }
        if (nLR[nLR.size() - 1].second >= LR[i].first) {
            nLR[nLR.size() - 1].second = max(nLR.back().second, LR[i].second);
        } else {
            nLR.push_back(LR[i]);
        }
    }

    for (int i = 0; i < nLR.size(); i++) {
//        cout << nLR[i].first << " "  << nLR[i].second << endl;
        for (int j = nLR[i].first; j <= nLR[i].second; j++) {
            str[j] = '*';
        }
    }
    printf("%s\n", str);
    


    return 0;
}
