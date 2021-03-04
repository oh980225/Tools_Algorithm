//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll dp[2000][2000];
//ll n, r, ans;
//ll mod = 1e9 + 7;
//
//ll go(int n, int r) {
//	if (n - r == 1 || r == 1) 
//		return n;
//	if (n == r || r == 0) 
//		return 1;
//
//	ll res = dp[n][r];
//	if (~res)
//		return res;
//
//	return res = (go(n - 1, r - 1) % mod + go(n - 1, r) % mod) % mod;
//}
//
//// top-down
//int main() {
//	cin >> n >> r;
//	memset(dp, -1, sizeof(dp));
//
//	cout << go(n, r);
//
//	return 0;
//}


//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll dp[2000][2000];
//ll n, r, ans;
//ll mod = 1e9 + 7;
// bottom-up
//int main() {
//	cin >> n >> r;
//	dp[0][0] = 1;
//	
//	for (int i = 1; i < 2000; i++) {
//		for (int j = 0; j <= i; j++) {
//			if (j > 0)
//				dp[i][j] += dp[i - 1][j - 1];
//			dp[i][j] += dp[i - 1][j];
//			dp[i][j] %= mod;
//		}
//	}
//
//	ans = dp[n][r];
//
//	cout << ans;
//
//	return 0;
//}