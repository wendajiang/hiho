#include "include.h"
// #include <bits/stdc++.h>
using namespace std;

vector<int> split(string s){
    vector<int> res;
    s += ".";
    int size = s.size();
    int num = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == '.'){
            res.push_back(num);
            num = 0;
        }else{
            num = num * 10 + s[i] - '0';
        }
    }
    return res;
}

bool cmp(string a, string b){
    vector<int> av = split(a);
    vector<int> bv = split(b);
    int size = min(av.size(), bv.size());
    for(int i = 0; i < size; i++){
        if(av[i] > bv[i]){
            return false;
        }else if(av[i] < bv[i]){
            return true;
        }else{
            continue;
        }
    }
    if(av.size() < bv.size()) return true;
    else return false;
    
}

int main(){

    int N;
    while(scanf("%d", &N) == 1 && N){
        vector<string> a;
        for(int i = 0; i < N; i++){
            string tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end(), cmp);
//        for(int i = 0; i < a.size(); i++){
//            int min = i;
//            for(int j = i; j < a.size(); j++){
//                if(cmp(a[j], a[min])) min = j;
//            }
//            swap(a[i], a[min]);
//        }
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << endl;
        }
    }

    return 0;
}
