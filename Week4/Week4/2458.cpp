#include<bits/stdc++.h>

using namespace std;

vector<int> compare[2][501];
int chk[2][501];
int n, m, ans;

void go(int f, int s) {
	if (chk[f][s]) return;
	chk[f][s] = 1;
	for (auto element : compare[f][s]) {
		go(f, element);
	}
}

int main() {
	cin >> n >> m;

	int first;
	int second;
	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		compare[0][first].push_back(second);
		compare[1][second].push_back(first);
	}

	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		go(0, i);
		go(1, i);
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (chk[0][j] || chk[1][j]) {
				cnt++;
			}
		}
		if (cnt == n) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}