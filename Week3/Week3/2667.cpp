#include <bits/stdc++.h>

using namespace std;

int n;
string matrix[30];
bool chk[30][30];
vector<int> ans;
int cnt;

struct MOVE {
	int x, y;
};

MOVE moveArr[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void dfs(int x, int y) {
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nX = x + moveArr[i].x;
		int nY = y + moveArr[i].y;
		if (0 <= nX && nX < n && 0 <= nY && nY < n && matrix[nY][nX]-'0' == 1) {
			matrix[nY][nX] = '0';
			dfs(nX, nY);
		}
	}

	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> matrix[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] - '0' == 1) {
				cnt = 0;
				matrix[i][j] = '0';
				dfs(j, i);
				ans.push_back(cnt);
			}
		}
	}

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}