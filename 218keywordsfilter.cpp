#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

const int NUM = 26;

vector<pair<int, int>> LR;

struct TNode {
    bool isStr;
    int len;
    int cnt;
    TNode *next[NUM];
    TNode *fail;
    TNode(): isStr(false), len(0), fail(NULL), cnt(0) {
        for (int i = 0; i < NUM; i++) {
            next[i] = NULL;
        }
    }
};

void Insert(TNode* root, const string& word) {
    TNode* location = root;
    int i = 0;
    while(i < word.size()){
        if (location->next[word[i] - 'a'] == NULL) {
            location->next[word[i] - 'a'] = new TNode();
        }
        location = location->next[word[i] - 'a'];
        i++;
    }
    location->isStr =  true;
    location->len = word.size();
    location->cnt++;
}

void Build(TNode* root) {
    queue<TNode*> q;
    q.push(root);
    while(!q.empty()) {
        TNode* now = q.front();
        q.pop();
        for (int i = 0; i < NUM; i++) {
            TNode* son = now->next[i];
            TNode* tp = (now == root) ? root : now->fail->next[i];
            if (son == NULL) {
                now->next[i] = tp;
            } else {
                son->fail = tp;
                q.push(son);
            }
        }
    }
}

void Search(TNode* root, const string& s){
    TNode* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        cur = cur->next[c];
        TNode* p = cur;
        while(p != root) {
            if (p->len) {
                pair<int, int> tmp;
                tmp.first = i - p->len + 1;
                tmp.second = i;
                LR.push_back(tmp);
            }
            p = p->fail;
        }
        
    }
}



int main(){
//    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    TNode* root = new TNode();
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        Insert(root, tmp);
    }
    Build(root);

    string S;
    cin >> S;
    Search(root, S);
    // for (int i = 0; i < LR.size(); i++) {
    //     cout << LR[i].first << " "  << LR[i].second << endl;
    // }
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
            S[j] = '*';
        }
    }
    cout << S << endl;
    
    return 0;
}
