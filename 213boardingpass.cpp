#include <iostream>
#include <string> 
#include <vector> 
#include <map>
#include <set>

using namespace std;

void hh() {
    map<string, int> indegree;
    map<string, int> outdegree;
    set<string> con;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            string tmp;
            cin >> tmp;
            con.insert(tmp);
            if ( j == 0 ){
                outdegree[tmp]++;
            }else {
                indegree[tmp]++;
            }
        }
        
    }
    pair<string, string> ret;
    for(auto tmps : con){
        if (outdegree[tmps] - indegree[tmps] == 1) {
            ret.first = tmps;
        }
        if (outdegree[tmps] - indegree[tmps] == -1){
            ret.second = tmps;
        }
    }

    cout << ret.first << " " << ret.second << endl;
}

int main() {
    hh(); 

	return 0;
}
