#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e6 + 1;

int p[MAXN], len1, len2, ans;
char s[MAXN], str[MAXN];

void init() {
    memset(p, 0, sizeof(0));
    str[0] = '$';
    str[1] = '#';
    len1 = strlen(s);
    for (int i = 0; i < len1; i++) {
        str[2 * i + 2] = s[i];
        str[2 * i + 3] = '#';
    }
    str[2 * len1 + 2] = '&';
    len2 = 2 * len1 + 2;
}

void manacher() {
    int id = 0, mx = 0;
    for (int i = 0; i < len2; i++) {
        if (mx > id) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        for (; str[i - p[i]] == str[i + p[i]]; p[i] ++);
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        init();
        manacher();
        ans = 0;
        for (int i = 0; i <= len2; i++) {
            ans = max(ans, p[i]);
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
