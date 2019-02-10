#include<cstdio>
int n,p[105],ans=1;
int gcd(int m,int n){return n?gcd(n,m%n):m;}
int lcm(int m,int n){return m/gcd(m,n)*n;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
    {
        int now=p[i],cnt=1;
        while(1)
        {
            if(now==i) break;
            else
            {
                now=p[now];
                cnt++;
            }
        }
        ans=lcm(ans,cnt);
    }
    printf("%d\n",ans);
}
