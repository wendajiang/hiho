#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = 1000 + 5;

int A[maxn];
int f[maxn][maxn];
int partition(vector<int>& id, vector<int>& count, int l, int r){
    int first = l - 1;
    int q = count[r];
    for(int second = l; second < r; second++){
        if(count[second] <= q){
            first++;
            int tmp = count[first];
            count[first] = count[second];
            count[second] = tmp;
            int tmpid = id[first];
            id[first] = id[second];
            id[second] = tmpid;
        }
    }
    first++;
    count[r] = count[first];
    count[first] = q;
    int tmpid = id[first];
    id[first] = id[r];
    id[r] = tmpid;
    return first;
}

void quicksort(vector<int>& id, vector<int>& count, int l, int r){
    if(l < r){
        int q = partition(id, count, l, r);
        quicksort(id, count, l, q - 1);
        quicksort(id, count, q + 1, r);
    }  
}



int main(){
    int n, m;
    memset(f, 0, sizeof(f));

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        // count[A[i]] ++;
    }
    sort(A + 1, A + n + 1);
    vector<int> id;
    vector<int> count;
    id.push_back(A[1]);
    count.push_back(1);
    int len = 2;
    while(len <= n){
        while(id[id.size() - 1] == A[len]){
            count[count.size() - 1]++;
            len++;
        } 
        id.push_back(A[len]);
        count.push_back(1);
        len++;
    }

//    for(int i = 0; i < id.size(); i++){
//        cout << id[i] << " " << count[i] << endl;
//    }

//    vector<int> score;
//    for(int i = 0; i < id.size(); i++){
//        score.push_back(id[i] * count[i]);
//    }
//
//    quicksort(id, score, 0, id.size() - 1);
//
//    reverse(score.begin(), score.end());
//    reverse(id.begin(), id.end());
////    for(int i = 0; i < id.size(); i++){
////        cout << id[i] << " " << score[i] << endl;
////    }
//    int ans = score[0];
//    int end = 1;
//    int mc = 1;
//    while(mc <= m && end < score.size()){
//        if(abs(id[end] - id[end - 1]) < 2){
//            end++; continue;
//        }
//        ans += score[end];
//        end++;
//        mc ++;
//    }
//    cout << ans << endl;

     //f[i][j] 从前i个包里，选了j个的最高分数

    //背包问题  *****

    for (int j=1;j<=m;j++) f[1][j]=id[0]*count[0];
	for (int i=1;i<id.size();i++) {
		if (id[i]-id[i-1]>1) {
			for (int j=1;j <= m;j++) {
				f[i+1][j]=f[i][j];
				if (f[i][j-1]+id[i]*count[i]>f[i+1][j]) f[i+1][j]=f[i][j-1]+id[i]*count[i];
			}
		} else {
			for (int j=1;j <= m;j++) {
				f[i+1][j]=f[i][j];
				if (f[i-1][j-1]+id[i]*count[i]>f[i+1][j]) f[i+1][j]=f[i-1][j-1]+id[i]*count[i];
			}
		}
	}
    // for(int i = 1; i <= id.size(); i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[id.size()][m] << endl;
}