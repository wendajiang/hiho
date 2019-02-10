#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100000 + 5;
int A[maxn];
int record[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    record[0] = A[0];
    int len = 0;
    for(int i = 0; i < n; i++){
        if(A[i] < record[len]) record[++len] = A[i];
        else{
            //find the first less than A[i]
            int l = 0, r = len, mid = 0;
            while(l < r){
                mid = l + (r - l) / 2;
                if(record[mid] >= A[i]) l = mid + 1;
                else r = mid;
            }
            record[l] = A[i];
        }
    }
    cout << n - len - 1 << endl;
}