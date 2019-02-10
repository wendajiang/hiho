#include <bits/stdc++.h>
using namespace std;


int main() {
	int N;
	vector<int> bag;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char flag;
		int w;
		cin >> flag;
		if (flag == 'A') {
			scanf("%d", &w);
			bag.push_back(w);
			push_heap(bag.begin(), bag.end());
			
		} else if (flag == 'T') {
			pop_heap(bag.begin(), bag.end());
			int getW = bag.back();
			bag.pop_back();
			printf("%d\n", getW);
		}	
	}
	return 0;
}