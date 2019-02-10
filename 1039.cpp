#include "include.h"

using namespace std;

const int maxn = 100 + 5;

string s;

pair<int, string> del(string p){
    int len = p.size ();
    if (len == 0) return make_pair(0, "");
    string t = "";
    int l = 0;
    p += ",";
    for (int i = 1 ; i < len + 1 ; i ++) {
        if (p[i] != p[i - 1]) {
            if (l == i - 1) {
                t += p[i - 1];
            }
            l = i;
        }
    }
    if (t.size () == len) return make_pair(0, t);
    pair<int, string> tmp = del(t);
    return make_pair(len - t.size () + tmp.first, tmp.second);
}



//int main(){
//    int t;
//    cin >> t;
//    while(t--){
//        cin >> s;
//        int ans = 0;
//        for(int i = 0; i < s.size(); i++){
//            string e = s;
//            e.insert(i, "A");
//            ans = max(ans, del(e));
//            e = s;
//            e.insert(i, "B");
//            ans = max(ans, del(e));
//            e = s;
//            e.insert(i, "C");
//            ans = max(ans, del(e));
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int len = s.size();
        pair<int, string> hello = del(s);
        int delnum = hello.first;
        string ss = hello.second;
        cout << ss;
        int remain = ss.size();
        if(remain == 0){
            cout << len + 1 << endl;
        }else{
            int k = 0;
            for(int i = 0; i < remain; i++){
                int xx = 0;
                while(i - xx >=0 && i + xx < remain && ss[i - xx] == ss[i + xx]) xx++;
                if(xx > k) k = xx;
            }
            cout << len - remain + 2 * k << endl;
        }
    }
}