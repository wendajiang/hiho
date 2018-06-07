#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10e5 + 1;

int n,m;

typedef struct edge{
	int from;
	int to;
	int w;
}Edge;

vector<Edge> edges;
vector<int> G[MAXN];

Edge s_u;
int res = 0;
bool vis[MAXN];

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 0, from, to, weight; i < m; i++){
		scanf("%d%d%d", &from, &to, &weight);
		Edge e;
		e.from = from; e.to = to; e.w = weight;
		if(i == 0) s_u = e;
		edges.push_back(e);
		int idx = edges.size() - 1;

		bool isChanged = false;
		for(int j = 0; j < G[from].size(); j++){
			int iTmp = G[from][j];
			if(from == edges[iTmp].from && edges[iTmp].to == to && edges[iTmp].w > weight){
				edges[iTmp].w = weight;
				isChanged = true;
			}
		}
		if(!isChanged){
			G[from].push_back(idx);
			G[to].push_back(idx);
		} 
		
	}
}

void prim(){
	memset(vis, false, sizeof(vis));
	vis[s_u.from] = true;
	auto cmp = [](Edge l, Edge r) { return l.w > r.w; };
	priority_queue<Edge, vector<Edge>, decltype(cmp)> Q(cmp);
	Q.push(s_u);
	int kase = n - 1;
	while(kase){
		Edge u = Q.top(); Q.pop();
		int l = u.from, r = u.to;
		while(!Q.empty() && vis[r]){
			u = Q.top(); Q.pop();
			l = u.from; r = u.to;
		}
		if(vis[r]) {
			return;
		}else{
			vis[r] = true;
			res += u.w;
			kase--;
		}

	}
	printf("%d\n", res);
}



int main(){
	init();
	prim();
	return 0;
}

