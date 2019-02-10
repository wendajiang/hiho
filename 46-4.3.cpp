#include<bits/stdc++.h>
using namespace std;
const int MAX=2e6;
const int MOD=1e9+7;
const double PI=acos(-1);
typedef long long ll;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int a[MAX],b[MAX];
ll p[32][2];
ll ans=0;
void add(int x)
{
    for(int i=0;i<=20;i++,x/=2)p[i][x%2]++;
}
void cla(int x)
{
    for(int i=0;i<=20;i++,x/=2)ans+=(1ll<<i)*p[i][(x%2)^1];
}
void Sort(int L,int m,int R)
{
    int x=L,y=m+1,len=0;
    memset(p,0,sizeof p);
    while(x<=m&&y<=R)
    {
        if(a[x]<=a[y])
        {
            b[len++]=a[x];
            cla(a[x]);
            x++;
        }
        else
        {
            b[len++]=a[y];
            add(a[y]);
            y++;
        }
    }
    while(x<=m)
    {
        b[len++]=a[x];
        cla(a[x]);
        x++;
    }
    while(y<=R)b[len++]=a[y++];
    for(int i=L;i<=R;i++)a[i]=b[i-L];
    //printf("[%d,%d] ans=%lld\n",L,R,ans);
}
void Merge(int l,int r)
{
    if(l==r)return;
    Merge(l,(l+r)/2);
    Merge((l+r)/2+1,r);
    Sort(l,(l+r)/2,r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Merge(1,n);
    cout<<ans<<endl;
    return 0;
}