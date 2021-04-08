//#include <bits/stdc++.h>
//
//using namespace std;
//
//string A;
//string B;
//
//int ans = 1e9;
//
//void dfs(string a, string b) {
//	int cnt = 0;
//	for (int i = 0; i < a.size(); i++) {
//		if (a[i] != b[i])
//			cnt++;
//	}
//	ans = min(cnt, ans);
//	return;
//}
//
//int main() {
//	cin >> A >> B;
//	string tmp;
//
//	for (int i = 0; i + A.size() <= B.size(); i++) {
//		tmp = B.substr(i, A.size());
//		dfs(A, tmp);
//	}
//
//	printf("%d", ans);
//	return 0;
//}