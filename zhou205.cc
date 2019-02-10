#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 100 + 1;

int n;
int arr[MAXN];

int btree[MAXN][2];
int root;

void init(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	memset(btree, -1, sizeof(btree));
	root = -1;
}

int buildTree(int l, int r){
	if(l == r) {
		printf("%d ", arr[l]);
		return l;
	}
	if(l > r) return -1;

	int iMin = l;
	for(int i = l; i <= r; i++){
		if(arr[i] < arr[iMin]){
			iMin = i;
		}
	}

	printf("%d ", arr[iMin]);

	int ileft = buildTree(l, iMin - 1);
	int iright = buildTree(iMin + 1, r);
	btree[iMin][0] = ileft;
	btree[iMin][1] = iright;
	return iMin;
}

void printpre(int i){
	printf("%d ", arr[i]);
	if(btree[i][0] != -1) printpre(btree[i][0]);
	if(btree[i][1] != -1) printpre(btree[i][1]);
}

void solve(){
	init();
	root = buildTree(0, n - 1);

	// printf("root is %d\n", root);
	// printpre(root);
	printf("\n");
}

int main(){
	solve();
	return 0;
}