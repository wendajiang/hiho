#include <bits/stdc++.h> 
using namespace std;

struct Member  
{  
    int color = 0;  
    vector<int> s, p;//son,parent  
}mbs[100001];  
  
bool is[100001];//unstable  
int N;  
  
bool all_colored(int v, int color)  
{  
    bool res = true;  
    for(int i = 0; res && i < mbs[v].p.size(); i++)  
        res &= (mbs[mbs[v].p[i]].color == color);  
    return res;  
}  
  
void topo(int v)  
{  
    if(mbs[v].color != 0)  
        return;  
  
    int color = v;  
    mbs[v].color = v;  
    queue<int> que;  
    que.push(v);  
    while(!que.empty())  
    {  
        int u = que.front();  
        que.pop();  
        for(int i = 0; i < mbs[u].s.size(); i++)  
        {  
            int s = mbs[u].s[i];  
            if(all_colored(s, color))  
            {  
                mbs[s].color = color;  
                que.push(s);  
                is[s] = true;  
            }  
        }  
    }  
  
}  
  
int main()  
{  
    cin >> N;  
    for(int i = 1; i <= N; i++)  
    {  
        int K;  
        cin >> K;  
        for(int j = 0; j < K; j++)  
        {  
            int p;  
            cin >> p;  
            mbs[p].s.push_back(i);  
            mbs[i].p.push_back(p);  
        }  
    }  
      
    memset(is, 0, sizeof(is));  
  
    for(int i = 1; i <= N; i++)  
        topo(i);  
    int res = 0;  
    for(int i = 1; i <= N; i++)  
        res += is[i];  
    cout << N - res << endl;  
    return 0;  
}  