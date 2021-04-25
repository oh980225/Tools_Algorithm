#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int matrix[101][101];
int check[101][101];

struct MOVE {
	int x, y;
};

MOVE moveArr[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void bfs(int x, int y) {
	queue<MOVE> q;
	q.push({ x, y });
	check[y][x] = 1;

	while (q.size()) {
		int fX = q.front().x;
		int fY = q.front().y;
		q.pop();

		if (fX == m - 1 && fY == n - 1) {
			ans = check[fY][fX];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nX = fX + moveArr[i].x;
			int nY = fY + moveArr[i].y;
			if (0 <= nX && nX < m && 0 <= nY && nY < n && !check[nY][nX] && matrix[nY][nX]) {
				check[nY][nX] = check[fY][fX] + 1;
				q.push({ nX, nY });
			}
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			matrix[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	cout << ans;

	return 0;
}