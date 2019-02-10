#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;

struct node{
    int l, r;
    int mm;

}tree[MAXN * 4];

int a[MAXN];

void push_up(int x) {
    tree[x].mm = min(tree[x << 1].mm, tree[x << 1 | 1].mm);
}

void build(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    tree[x].mm = 0;
    if (l == r) {
        tree[x].mm = a[l];
    } else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}


void update(int x, int p,int val) {
    int L = tree[x].l, R = tree[x].r;
    if (L == R) {
        a[L] = val;
        tree[x].mm = val;
    } else {
        int mid = (L + R) / 2;
        if (p <= mid) update(x << 1, p, val);
        else update(x << 1 | 1, p, val);
        push_up(x);
    }
}

int query(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        return tree[x].mm;
    } else {
        int ans = INT_MAX;
        int mid = (L + R) / 2;
        if (mid >= l) ans = min(ans, query(x << 1, l, r));
        if (r > mid) ans = min(ans, query(x << 1 | 1, l, r));
        return ans;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (x == 0) {
            int ret = query(1, l, r);
            printf("%d\n", ret);
        } else {
            update(1, l, r);
        }
    }

    return 0;
}
