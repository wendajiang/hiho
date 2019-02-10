#include <bits/stdc++.h>
using namespace std;
vector<int> xyz;

int cr, cy, cb;
int cMax;

string s;

bool isVanish() {
	int x_ = abs(cr - cy);
	int y_ = abs(cr - cb);
	int z_ = abs(cy - cb);
	vector<int> xyz_{x_, y_, z_};
	sort(xyz_.begin(), xyz_.end());
	bool res = true;
	for (int i = 0; i < 3; i++) {
		if (xyz_[i] != xyz[i]) {
			res = false;
			break;
		}
	}
	return res;
}

void init() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	xyz.push_back(x); xyz.push_back(y); xyz.push_back(z);
	sort(xyz.begin(), xyz.end());

	cin >> s;
}

void hh() {
	int len = s.size();
	cr = 0;
	cy = 0;
	cb = 0;
	cMax = 0;
	int cur = 0;
	for (int i = 0; i < len; i++) {
		cur++;
		cMax = max(cMax, cur);
		switch(s[i]){
			case 'R':
				cr++; break;
			case 'Y':
				cy++; break;
			case 'B':
				cb++; break;
		}
		if(isVanish()){
			cr = 0; cb = 0; cy = 0;
			cur = 0;
		}
	}
	printf("%d\n", cMax);
}

int main() {
	init();
	hh();
	return 0;
}