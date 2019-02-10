#include <bits/stdc++.h>
using namespace std;

const int CH = 26;
const int MAXN = 2e6 + 1;


char str[MAXN];
int cnt = 0;

struct TNode {
    TNode *next[CH];
    TNode *fail;
    int cnt;
    int len;
    bool isWord;
    TNode():isWord(false), cnt(0), len(0), fail(NULL) {
        for (int i = 0; i < CH; i++) {
            next[i] = NULL;
        }
    }
};

void Insert(TNode* root, char* str) {
    TNode* cur = root;
    int i = 0;
    for (; str[i]; i++) {
        int c = str[i] - 'a';
        if (cur->next[c] == NULL) {
            cur->next[c] = new TNode();
        }
        cur = cur->next[c];
        cur->cnt++;
    }
    cur->len = i;
    cur->isWord = true;

}

void Query(TNode* root) {
    // bfs compute cnt
    for (int i = 0; i < CH; i++) {
        TNode* cur = root->next[i];
        if (cur != NULL){
            if (cur->cnt <= 5) {
                cnt++;
            } else {
                Query(cur);
            }
        }
    }

}

int main () {
    int n;
    scanf("%d", &n);
    TNode* root = new TNode();
    cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        Insert(root, str);
    }
    Query(root);
    printf("%d\n", cnt);

    return 0;
}