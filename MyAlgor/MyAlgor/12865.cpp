#include <bits/stdc++.h>

using namespace std;

int dp[105][100005];
vector<pair<int, int>> prod;

int main() {
	int n, k;
	scanf_s("%d %d", &n, &k);

	int w, v;
	prod.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d %d", &w, &v);
		prod[i] = { w, v };
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= prod[i].first) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prod[i].first] + prod[i].second);
				continue;
			}
			dp[i][j] = dp[i - 1][j];
		}
	}

	printf("%d", dp[n][k]);

	return 0;
}