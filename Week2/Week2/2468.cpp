#include<bits/stdc++.h>

using namespace std;

int n, ans, maxNum;
int matrix[100][100];
int chk[100][100];

struct MOVE {
	int y, x;
};

MOVE moveArr[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void rain(int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] <= x) {
				matrix[i][j] = 0;
			}
		}
	}
}

void go(int i, int j) {
	chk[i][j]++;
	for (int k = 0; k < 4; k++) {
		int dY = i + moveArr[k].y;
		int dX = j + moveArr[k].x;
		if (0 <= dY && dY <= n - 1 && 0 <= dX && dX <= n - 1 && !chk[dY][dX] && matrix[dY][dX]) {
			go(dY, dX);
		}
	}

	return;
}

void check() {
	for (int x = 0; x <= maxNum; x++) {
		rain(x);

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] != 0) {
					if (!chk[i][j]) {
						cnt++;
						go(i, j);
					}
				}
			}
		}
		
		memset(chk, 0, sizeof(chk));
		ans = max(ans, cnt);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			maxNum = max(maxNum, matrix[i][j]);
		}
	}

	check();

	cout << ans << endl;
	return 0;
}