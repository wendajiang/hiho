#include <bits/stdc++.h>
using namespace std;

char pre[27], mid[27];
char post[27];

struct node{
    char a;
    struct node* left, *right;
    node(char a_): a(a_), left(NULL), right(NULL) {}
};

//struct node *root;

node* build(node* cur, int pres, int pree, int mids, int mide) {
    if (pres > pree || mids > mide) {
        return NULL;
    }

    if (pres == pree) {
        cur = new node(pre[pres]);
        return cur;
    }

    cur = new node(pre[pres]);
    char root = pre[pres];
    int i = mids;
    for (; i <= mide; i++) {
        if (mid[i] == root) break;
    }
    cur->left = build(cur->left, pres + 1, pres + i - mids, mids, i - 1);
    cur->right = build(cur->right, pres + i - mids + 1, pree,  i + 1, mide);
    return cur;
}

void func(node* root) {
    if (root == NULL) return;
    if (root->left) func(root->left);
    if (root->right) func(root->right);
    printf("%c", root->a);
}

int main(){
    scanf("%s%s", pre, mid);
    int len1 = strlen(pre);
    int len2 = strlen(mid);
    if (len1 != len2) return 0;
    node* root;
    root = build(root, 0, len1 - 1, 0, len2 - 1);
    func(root);
    return 0;
}
