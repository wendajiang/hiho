/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  9/ 3 16:41:06 2018
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
const int NUM = 26;
const char BASE = 'a';


struct TNode {
	int len;
	int cnt;
	bool isWord;
	TNode* next[NUM];
	TNode* fail;
	TNode():fail(NULL), len(0), cnt(0), isWord(false) {
		for (int i = 0; i < NUM; i++) {
			next[i] = NULL;
		}
	}
};

vector<pair<int, int>> LR;

void Insert(TNode* root, const string& str) {
	TNode* cur = root;
	for (int i = 0; i < str.size(); i++) {
		if (cur->next[str[i] - BASE] == NULL) {
			cur->next[str[i] - BASE] = new TNode();
		}
		cur = cur->next[str[i] - BASE];
	}
	cur->cnt++;
	cur->len = str.size();
	cur->isWord = true;
}

void Search(TNode* root, const string& str, int start) {
	TNode* cur = root;
	for (int i = start; i < str.size(); i++) {
		if (cur->next[str[i] - BASE] != NULL) {
			cur = cur->next[str[i] - BASE];
			if (cur->isWord) {
				pair<int, int> tmp;
				tmp.second = i;
				tmp.first = i - cur->len + 1;
				LR.push_back(tmp);
			}
		} else {
			return;
		}
	}
}

void Build(TNode* root) {
	
}

int main() {
    int n;
    cin >> n;
    string str;
    TNode* root = new TNode();
    for (int i = 0; i < n; i++) {
    	cin >> str;
    	Insert(root, str);
    }

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
    	Search(root, str, i);
    }

    // 合并LR的区间
    sort(LR.begin(), LR.end(), [](pair<int,int>& a, pair<int, int>& b) {
        return a.first < b.first;
    });
    vector<pair<int, int>> nLR;
    for (int i = 0; i < LR.size(); i++) {
        if (i == 0) {
            nLR.push_back(LR[i]);
            continue;
        }
        if (nLR[nLR.size() - 1].second >= LR[i].first) {
            nLR[nLR.size() - 1].second = max(nLR.back().second, LR[i].second);
        } else {
            nLR.push_back(LR[i]);
        }
    }

    for (int i = 0; i < nLR.size(); i++) {
//        cout << nLR[i].first << " "  << nLR[i].second << endl;
        for (int j = nLR[i].first; j <= nLR[i].second; j++) {
            str[j] = '*';
        }
    }
    cout << str << endl;

    return 0;
}

