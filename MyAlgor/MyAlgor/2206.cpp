#include <bits/stdc++.h>

using namespace std;

int n, m;
int check[1001][1001][2];
vector<string> matrix;

struct POS {
	int y, x;
};

vector<POS> v;
POS moveArr[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	check[0][0][1] = 1;
	while (q.size()) {
		int curX = q.front().first.second;
		int curY = q.front().first.first;
		int canBreak = q.front().second;
		q.pop();

		if ((curY == n - 1) && (curX == m - 1)) {
			return check[curY][curX][canBreak];
		}

		for (int i = 0; i < 4; i++) {
			int nX = curX + moveArr[i].x;
			int nY = curY + moveArr[i].y;
      
			if (0 <= nY && nY < n && 0 <= nX && nX < m && matrix[nY][nX] == '1' && canBreak) {
				check[nY][nX][canBreak - 1] = check[curY][curX][canBreak] + 1;
				q.push(make_pair(make_pair(nY, nX), canBreak - 1));
        continue;
			}

			if (0 <= nY && nY < n && 0 <= nX && nX < m && !check[nY][nX][canBreak] && matrix[nY][nX] == '0') {
				check[nY][nX][canBreak] = check[curY][curX][canBreak] + 1;
				q.push(make_pair(make_pair(nY, nX), canBreak));
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	matrix.resize(n);
	for (int i = 0; i < n; i++) 
		cin >> matrix[i];

	cout << bfs();
	return 0;
}