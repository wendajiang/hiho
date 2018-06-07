#include "include.h"
// #include <bits/stdc++.h>
using namespace std;
char op[] = {'+', '-', '*', '/', 'm', 'n'};
bool used[6];
char ops[3];
int nowNumber[4];
int number[4];

int cal(int a, int b, char op){
    switch(op){
        case '+':{
            return a + b;
        }
        case '-':{
            return a - b;
        }
        case '*':{
            return a * b;
        }
        case '/':{
            return a / b;
        }
        case 'm':{
            return b - a;
        }
        case 'n':{
            return b / a;
        }
    }
    return -1;
}

bool cal1(){
    int a = nowNumber[0], b = nowNumber[1], c = nowNumber[2], d = nowNumber[3];
    return cal(cal(cal(a, b, ops[0]), c, ops[1]), d, ops[2]);
}
bool cal2(){
    int a = nowNumber[0], b = nowNumber[1], c = nowNumber[2], d = nowNumber[3];
    return cal(cal(a, b, ops[0]), cal(c, d, ops[2]), ops[1]);
}

bool makeOp(int depth){
    if(depth >= 3){
        if(cal1()) return true;
        if(cal2()) return true;
        return false;
    }
    for(int i = 0; i < 6; i++){
        ops[depth] = op[i];
        if(makeOp(depth + 1))
            return true;
    }
    return false;
}

bool makeNumber(int depth){
    if(depth >= 4){
        return makeOp(0);
    }
    for(int i = 0; i < 4; i++){
        if(!used[i]){
            nowNumber[depth] = number[i];
            used[i] = true;
            if(makeNumber(depth + 1))
                return true;
            used[i] = false;
        }
    }
    return false;
}

void solve(){
    memset(used, false, sizeof(used));
    memset(ops, false, sizeof(ops));
    memset(nowNumber, 0, sizeof(nowNumber));
    int T;
    scanf("%d", &T);
    while(T--){
        memset(used, false, sizeof(used));
        memset(ops, false, sizeof(ops));
        memset(nowNumber, 0, sizeof(nowNumber));
        scanf("%d%d%d%d", &number[0], &number[1], &number[2], &number[3]);
        if(makeNumber(0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
}

int main(){
    solve();
    return 0;
}
