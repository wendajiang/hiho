#include "include.h"
//#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
int n,m,k,t;
vector<int>c,d,e;
int main()
{
    int i,j;
    long long a,b;
    scanf("%d%lld%lld",&n,&a,&b);
    long long p=1;
    for(i=0;i<n;i++)
    {
        c.push_back((a/p)%10);
        d.push_back(i);
        e.push_back((b/p)%10);
        p=p*10;
    }
    int ret=INT_MAX;
    do
    {
        vector<int>tmp,pos(n);
        tmp=d;
        int now=0;
        for(i=0;i<n;i++)pos[tmp[i]]=i;
        for(i=0;i<n;i++)
        {
            if(tmp[i]!=i)
            {
                pos[tmp[i]]=pos[i];
                swap(tmp[pos[i]],tmp[i]);
                now++;
            }
        }
        for(i=0;i<n;i++)assert(tmp[i]==i);
        for(i=0;i<n;i++)
        {
            now+=min(abs(c[d[i]]-e[i]),10-abs(c[d[i]]-e[i]));
        }
        ret=min(ret,now);
    }while(next_permutation(d.begin(),d.end()));
    printf("%d\n",ret);
    return 0;
}

