#include <bits/stdc++.h>

using namespace std;

vector<string> v;
pair<int, int> moveArr[4] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
bool chk[150];
int r, c;
int ans;

void dfs(int x, int y, int cur) {
	for (int i = 0; i < 4; i++) {
		int newX = x + moveArr[i].first;
		int newY = y + moveArr[i].second;
		if ((0 <= newX && newX < r) && 
			(0 <= newY && newY < c) &&
			!chk[v[newX][newY] - '0']) {
			chk[v[newX][newY] - '0'] = true;
			dfs(x + moveArr[i].first, y + moveArr[i].second, cur + 1);
			chk[v[newX][newY] - '0'] = false;
			continue;
		}
		ans = max(ans, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	chk[v[0][0] - '0'] = true;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}