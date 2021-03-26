#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int matrix[501][501];
int chk[501][501];

struct MOVE {
	int y, x;
};

MOVE moveArr[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

void go(int y, int x, int cur, int num) {
	if (num == 4) {
		ans = max(ans, cur);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int dX = x + moveArr[i].x;
		int dY = y + moveArr[i].y;
		if (0 <= dX && dX < m && 0 <= dY && dY < n && !chk[dY][dX]) {
			chk[dY][dX] = 1;
			go(dY, dX, cur + matrix[dY][dX], num + 1);
			chk[dY][dX] = 0;
		}
	}

	return;
}

void func(int y, int x) {
	int sum = 0;
	
	// 1
	if (0 <= x && x + 2 < m && 0 <= y && y + 1 < n) {
		sum = matrix[y][x] + matrix[y][x + 1] + matrix[y][x + 2] + matrix[y + 1][x + 1];
		ans = max(ans, sum);
	}
	// 2
	if (0 <= x && x + 1 < m && 0 <= y && y + 2 < n) {
		sum = matrix[y][x] + matrix[y + 1][x] + matrix[y + 2][x] + matrix[y + 1][x + 1];
		ans = max(ans, sum);
	}
	// 3
	if (0 <= x && x + 2 < m && 0 <= y - 1 && y < n) {
		sum = matrix[y][x] + matrix[y][x + 1] + matrix[y][x + 2] + matrix[y - 1][x + 1];
		ans = max(ans, sum);
	}
	// 4
	if (0 <= x && x + 1 < m && 0 <= y - 1 && y + 1 < n) {
		sum = matrix[y][x] + matrix[y][x + 1] + matrix[y - 1][x + 1] + matrix[y + 1][x + 1];
		ans = max(ans, sum);
	}

	return;
}

int main() {
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%d", &matrix[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			chk[i][j] = 1;
			go(i, j, matrix[i][j], 1);
			chk[i][j] = 0;
			func(i, j);
		}
	
	printf("%d", ans);
		
	return 0;
}