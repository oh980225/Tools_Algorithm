#include <bits/stdc++.h>

using namespace std; 

int dp[2][100005];
int num[2][100005];

int main() {
	int t;
	int n;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf_s("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				scanf_s("%d", &num[j][k]);
			}
		}
		dp[0][1] = num[0][1];
		dp[1][1] = num[1][1];
		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + num[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + num[1][j];
		}
		printf("%d\n", max(dp[0][n], dp[1][n]));
	}


	return 0;
}