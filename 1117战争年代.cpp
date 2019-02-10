/*************************************************************************
	> File Name: 1117战争年代.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  8/ 3 00:09:32 2018
 ************************************************************************/

#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef double db;
struct edge{
	int v,next;
}e[4005];int etot=0;int g[2005];
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
db p[2005];//rozne

int qu[2005];
int pre[2005],h[2005],upe[2005];
int n,m;
void bfs(int rt){
	int p=0,q=0;
	for (int i=1;i<=n;i++)pre[i]=h[i]=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
			h[e[i].v]=h[u]+1;
			pre[e[i].v]=u;
			upe[e[i].v]=i>>1;
			qu[q++]=e[i].v;
		}
	}
}

int main()
{
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ae(x,y);
		ae(y,x);
	}
	while(m--){
		int x,d;
		scanf("%d%d",&x,&d);
		bfs(x);
		for (int i=1;i<=n;i++)if(h[i]>=1 && h[i]<=d+1){
			p[upe[i]]=1.0/(d+1)+(h[i]-1.0)/(d+1)*p[upe[i]];
		}
	}
	db su = 1.0;
	for (int i=0;i<n-1;i++)su+=p[i];
	printf("%.10lf\n",su);
	return 0;
}



