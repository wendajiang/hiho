#include <bits/stdc++.h>
using namespace std;
int n;

void dfs(int r[], int cur, string pre) {
    if (cur == 1) {
        if (pre[pre.size() - 1] == '-' || r[0] > (pre[pre.size() - 1] - '0'))
            cout << pre << r[0] << endl;
        return;
    }
    for (int i = 0; i < cur; i++) {
        int nr[cur - 1], ncur = 0;
        for (int j = 0; j < cur; j++) if (i != j) nr[ncur++] = r[j];
        bool s = true;
        for (int j = pre.size() - 1; j >= 0; j--) {
            if (pre[j] == '-') break;
            if ((pre[j] - '0') > r[i]) s = false;
        }
        if (s) {
            dfs(nr, cur - 1, pre + to_string(r[i]) + "-");
            dfs(nr, cur - 1, pre + to_string(r[i]));
        }
    }
}

int main(){
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    dfs(arr, n, "");
    return 0;
}
