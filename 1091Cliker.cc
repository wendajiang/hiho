#include <bits/stdc++.h>
using namespace std;
const int kMaxn = 30 + 1;
const int kMaxm = 2e4 + 1;

void hh() {
	int i, n, m, bi, sum, maxk;  
    cin >> n >> m;  
    vector<int> a(n);  
    vector<vector<int>> b(n,vector<int>(2,0)), dp(n + 1,vector<int> (m + 1,0));  
    for (i = 0; i < n; ++i)  
    {  
        cin >> a[i] >> b[i][1];  
          
        bi = sum = b[i][1];  
        while (sum + bi*1.07 < m)  
        {  
            bi *= 1.07;  
            sum += bi;  
            b[i].push_back(sum);  
        }  
    }  
  
    for (i = 0; i < n; ++i)  
    {  
        maxk = b[i].size();  
        for (int j = 1; j <= m; ++j)  
        {  
            for (int k = 0; k<maxk; k++)  
            {  
                if (j < b[i][k])  
                    break;  
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - b[i][k]] + k*a[i]);  
            }  
        }  
    }  
    cout << dp[n][m] << endl;  
}

int main () {
	hh();
	return 0;
}