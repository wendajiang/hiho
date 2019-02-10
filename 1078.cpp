//区间赋值
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

struct node {
    int l, r;
    long long sum;
    int lazyset;

}tree[MAXN << 2];

int a[MAXN];

void push_up(int x) {
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

void push_down(int x) {
    if (tree[x].lazyset != -1){
        int lazy = tree[x].lazyset;
        tree[x].lazyset = -1; //清除标记
        tree[x << 1].lazyset = lazy;
        tree[x << 1].sum = 1LL * (tree[x<<1].r - tree[x << 1].l + 1) * lazy;
        tree[x << 1 | 1].lazyset = lazy;
        tree[x << 1 | 1].sum = 1LL * (tree[x << 1 | 1].r - tree[x << 1 | 1].l + 1) * lazy;
    }
}

void build(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    tree[x].sum = 0;
    tree[x].lazyset = -1;
    if (l == r) {
        tree[x].sum = a[l];
    } else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}

void Set(int x, int l, int r, int val) {
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        tree[x].lazyset = val;
        tree[x].sum = 1LL * (R - L + 1) * val;
    } else {
        push_down(x);
        int mid = (L + R) / 2;
        if (mid >= l) Set(x << 1, l, r, val);
        if (r > mid) Set(x << 1 | 1, l, r, val);
        push_up(x);
    }
}

long long querySet(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    if (l <= L && R <= r) {
        return tree[x].sum;
    } else {
        push_down(x);
        long long ans = 0;
        int mid = (L + R) / 2;
        if (mid >= l) ans += querySet(x << 1, l ,r);
        if (r > mid) ans += querySet(x << 1 | 1, l, r);
        push_up(x);
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
        int x;
        scanf("%d", &x);
        if (x == 0) {
            int l, r;
            scanf("%d%d", &l, &r);
            long long ret = querySet(1, l, r);
            printf("%lld\n", ret);
        } else {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            Set(1, l, r, val);
        }
    }
    return 0;
}
