#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int maxCnt;
bool flag;
bool check[35][15];

void dfs(int row, int cnt) {
	if (flag)
		return;

	if (maxCnt == cnt) {
		bool possible = true;
		for (int i = 1; i <= n; i++) {
			int col = i;
			for (int j = 1; j <= h; j++) {
				if (check[j][col])
					col++;
				else if (check[j][col - 1])
					col--;
			}
			if (i != col) {
				possible = false;
				break;
			}
		}
		if (possible)
			flag = true;
		return;
	}

	for (int i = row; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j] && !check[i][j - 1] && !check[i][j + 1]) {
				check[i][j] = true;
				dfs(i, cnt + 1);
				check[i][j] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> n >> m >> h;

	int f, s;
	for (int i = 0; i < m; i++) {
		cin >> f >> s;
		check[f][s] = true;
	}

	for (int i = 0; i <= 3; i++) {
		maxCnt = i;
		dfs(1, 0);
		if (flag) {
			cout << maxCnt;
			return 0;
		}
	}

	cout << -1;

	return 0;
}