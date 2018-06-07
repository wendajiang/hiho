// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <cstdio>
// #include <climits>

// //暴力求解，看行不行
// //暴力TLE，结果没错

// //通过剪枝优化，比暴力好一点

// using namespace std;

// const int maxn = 300 + 5;

// int matrix[maxn][maxn];
// int sum[maxn][maxn];


// int main(){
//     int N, M, K;
//     while(scanf("%d%d%d", &N, &M, &K) == 3){
//         memset(sum, 0, sizeof(sum));
//         memset(matrix, 0, sizeof(matrix));
//         for(int i = 1; i <= N; i++){
//             for(int j = 1; j <= M; j++){
//                 scanf("%d", &matrix[i][j]);
//                 sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//             }
//         }
// //        for(int i = 1; i <= N; i++){
// //            for(int j = 1; j <= M; j++){
// //                cout << sum[i][j] << " ";
// //            }
// //            cout << endl;
// //        }

//         int block = -1;
//         for(int i = 0; i < N; i++)
//             for(int l = N; l >= i + 1; l--){
//                 if(block >= (l - i) * M) break;
//                 for(int j = 0; j < M; j++){
//                     if(block >= (l - i) * (M - j)) break;
//                     for(int k = M; k >= j + 1; k--){
//                         if(block >= (l - i) * (k - j)) break;
//                         int tot = sum[l][k] + sum[i][j] - sum[l][j] - sum[i][k];
//                         if(tot <= K) block = max(block, (l - i) * (k - j));
//                     }
//                 }
//             }

//         cout << block << endl;
//     }
// }


//类似的过程，优化
//通过二叉搜索来优化过程，比剪枝可能更快一点

#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int maxn=310;
int N,M,K;
int a[maxn][maxn];
int sum[maxn][maxn],temp[maxn],q[maxn],head,tail;
int ans=-1;
struct in
{
	int pos;int s;
}c[maxn];
inline int mymax(int xx,int yy){if(xx>yy)return xx;return yy;}
 int bsearch(int x){
	int L=1,R=tail,mid;
	while(L+1<R){
		mid=(L+R)>>1;
		if(q[mid]<=x)
			L=mid;
		else if(temp[q[mid]]-temp[x-1]<=K)
			L=mid;
		else
			R=mid;
	}
	if(temp[q[R]]-temp[x-1]<=K)
		return q[R];
	if(temp[q[L]]-temp[x-1]<=K)
		return q[L];
	return -1;
}
int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%d",&a[i][j]);
	for(int j=1;j<=M;j++)
		for(int i=1;i<=N;i++)
			sum[i][j]=sum[i-1][j]+a[i][j];
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++){
			for(int k=1;k<=M;k++)
				temp[k]=temp[k-1]+sum[j][k]-sum[i-1][k];
			head=1,tail=0;
			for(int k=1;k<=M;k++){
				while(head<=tail&&temp[k]<=temp[q[tail]])
					tail--;
				q[++tail]=k;
			}
			for(int k=1;k<=M;k++){
				if((M-k+1)*(j-i+1)<=ans)
					break;
				int t=bsearch(k);
				ans=mymax(ans,(t-k+1)*(j-i+1));
			}
		}
	printf("%d\n",ans);
	return 0;
}