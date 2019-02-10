#include "include.h"
// #include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m;
int tot;
string str[maxn];
int c[maxn], r[maxn];

long long row, col;
void skip(int step)
{
	for (int i = 0; i < step; i++)
	{
		for (int k = 0; k < tot; k++)
		{
			if (col == m) col = 0, row++;
			col++;
			if (col + str[k].size() > m) col = 0, row++;
			col += str[k].size();
		}
	}
}

int main()
{
	cin >> n >> m;
    getchar();
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
	row = 1, col = 0;
	while (ss >> str[tot]) tot++;
	memset(c, -1, sizeof(c));
	for (int k = 0; k < tot; k++)
	{
		if (k)
		{
			if (col == m) col = 0, row++;
			col++;
		}
		if (col + (int)str[k].size() > m) col = 0, row++;
		col += str[k].size();
	}
	if (m <= 100000)
	{
		c[col] = 1;
		r[col] = row;
		for (int i = 2; i <= n; i++)
		{
			skip(1);
			if (~c[col])
			{
				long long dt = (n - c[col]) % (i - c[col]);
				long long dt_row = row - r[col];
				long long rd = (n - i) / (i - c[col]);
				row += rd * dt_row;
				skip(dt);
				break;
			}
			c[col] = i;
			r[col] = row;
		}
	}
	else
	{
		int tot_sz = 0;
		for (int i = 0; i < tot; i++)
			tot_sz += 1 + str[i].size();
		for (int i = 1; i < n; )
		{
			long long rd = min((m - col) / tot_sz, (long long)n - i);
			i += rd;
			col += tot_sz * rd;
			if (i < n)
			{
				skip(1);
				i++;
			}
		}
	}
	cout << row << " " << col << endl;
}
