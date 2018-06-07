#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

/*
bfs方法LTE，方法没什么问题
*/

const int maxn = 100000 + 5;

char s[maxn], t[maxn];

void exchange(char* p, int i, int j){
    char tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void bfs(){
    int ans = -1;
    int tmpans = -1;
    vector<string> qq;
    int start = 0, end = 1;
    string u = s;
    qq.push_back(u);
    end = qq.size();
    while(start < end){
        int tmpend = end;
        tmpans += 1;
        for(int l = start; l < tmpend; l++){
            string u = qq[l];
            char uu[maxn];
            strcpy(uu, u.c_str());
            if(strcmp(uu, t) == 0) {
                ans = tmpans;
                cout << ans << endl;
                return;
            }
            int len = strlen(uu);
            char w[maxn];
            memset(w, 0, sizeof(w));
            for(int i = 0; i < len; i++){
                if(uu[i] == '_'){
                    if(i - 1 > 0 && uu[i - 1] == 'R') w[i] ++;
                    if(i + 1 < len && uu[i + 1] == 'L') w[i] ++;
                }
            }
            for(int i = 0; i < len; i++){
                if(w[i]){
                    if(w[i] == 1){
                        if(i - 1 > 0 && uu[i - 1] == 'R') {
                            char v[maxn];
                            memcpy(v, uu, maxn);
                            exchange(v, i, i - 1);
                            string buff = v;
                            qq.push_back(buff);
                            end = qq.size();
                        }else{
                            char v[maxn];
                            memcpy(v, uu, maxn);
                            exchange(v, i, i + 1);
                            string buff = v;
                            qq.push_back(buff);
                            end = qq.size();
                        }
                    }else if(w[i] == 2){
                        char v[maxn];
                        memcpy(v, uu, maxn);
                        exchange(v, i, i - 1);
                        string buff = v;
                        qq.push_back(buff);
                        memcpy(v, uu, maxn);
                        exchange(v, i, i + 1);
                        buff = v;
                        qq.push_back(buff);
                        end = qq.size();
                    }
                }else {
                    continue;
                }
            }
        }
        start = tmpend;
    }

    cout << ans << endl;
}

int main(){
    scanf("%s%s", s, t);

    int lens = strlen(s);
    int lent = strlen(t);
    if(lens != lent) cout << -1 << endl;
    bfs();
    return 0;
}