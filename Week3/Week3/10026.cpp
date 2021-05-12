#include <bits/stdc++.h>

using namespace std;

int n, ans1, ans2;
vector<string> rgb;
bool check[105][105];
struct POS {
	int y, x;
};
POS moveArr[4] = { {0, 1}, {1, 0}, {-1, 0} ,{0, -1} };

void dfs(int y, int x, char pre) {
	for (int i = 0; i < 4; i++) {
		int nY = y + moveArr[i].y;
		int nX = x + moveArr[i].x;
		if (0 <= nY && nY < n && 0 <= nX && nX < n && !check[nY][nX] && pre == rgb[nY][nX]) {
			if (rgb[nY][nX] == 'G')
				rgb[nY][nX] = 'R';
			check[nY][nX] = true;
			dfs(nY, nX, pre);
		}
	}
}

int main() {
	cin >> n;
	rgb.resize(n);
	for (int i = 0; i < n; i++)
		cin >> rgb[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				ans1++;
				check[i][j] = true;
				dfs(i, j, rgb[i][j]);
				if (rgb[i][j] == 'G')
					rgb[i][j] = 'R';
			}
		}
	}

	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				ans2++;
				check[i][j] = true;
				dfs(i, j, rgb[i][j]);
			}
		}
	}

	cout << ans1 << " " << ans2;

	return 0;
}