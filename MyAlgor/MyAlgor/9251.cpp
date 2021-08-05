#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main() {
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;
	
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				continue;
			}
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	printf("%d", dp[s1.size()][s2.size()]);
	return 0;
}