#include<bits/stdc++.h>

using namespace std;

string str;
bool dp[2000][2000];
int n;

// bottom-up
int main() {
	cin >> n;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j + i < str.size(); j++) {
			if (i < 2)
				dp[j][i + j] = (str[j] == str[i + j]);
			else
				dp[j][i + j] = ((str[j] == str[i + j]) && dp[j + 1][i + j - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		int s;
		int e;
		cin >> s >> e;
		cout << dp[s][e];
		puts("");
	}

	return 0;
}



//#include<bits/stdc++.h>
//
//using namespace std;
//
//string str;
//int dp[2000][2000];
//int n;
//
//bool go(int s, int e) {
//	if (s == e)
//		return 1;
//	if (e - s == 1)
//		return str[s] == str[e];
//
//	int& res = dp[s][e];
//	if (~res)
//		return res;
//
//	res = 0;
//	if (str[s] == str[e])
//		return res = go(s + 1, e - 1);
//	return res;
//}
//// top-down
//int main() {
//	cin >> n;
//	cin >> str;
//	memset(dp, -1, sizeof(dp));
//
//	for (int i = 0; i < n; i++) {
//		int s;
//		int e;
//		cin >> s >> e;
//		cout << go(s, e);
//	}
//
//	return 0;
//}