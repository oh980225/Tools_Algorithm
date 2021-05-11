#include <bits/stdc++.h>

using namespace std;

int m, n;
int matrix[1005][1005];
int check[1005][1005];

struct POS {
	int y, x;
};

POS moveArr[4] = { {0, 1}, {1, 0 }, {-1 ,0}, {0 ,-1} };
vector<POS> pos;

void bfs() {
	queue<POS> q;

	for (auto element : pos) {
		check[element.y][element.x] = 1;
		q.push(element);
	}

	while (q.size()) {
		POS f = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nX = f.x + moveArr[i].x;
			int nY = f.y + moveArr[i].y;
			if (0 <= nX && nX < m && 0 <= nY && nY < n && !check[nY][nX] && matrix[nY][nX] != -1) {
				q.push({ nY, nX });
				matrix[nY][nX] = 1;
				check[nY][nX] = check[f.y][f.x] + 1;
			}
		}
	}
}

int main() {
	cin >> m >> n;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				pos.push_back({ i, j });
			}
		}
	}

	if (!pos.size()) {
		cout << -1;
		return 0;
	}

	bfs();

	int maxCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxCnt = max(maxCnt, check[i][j]);
			if (matrix[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << maxCnt - 1;

	return 0;
}