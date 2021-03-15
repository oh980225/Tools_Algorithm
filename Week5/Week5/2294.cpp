//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, k;
//vector<int> v;
//int memo[10001];
//
//// bottom-up
//int main() {
//	scanf("%d %d", &n, &k);
//
//	v.resize(n);
//
//	memset(memo, 0x3f, sizeof(memo));
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//		if (v[i] <= 10000)
//			memo[v[i]] = 1;
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 1; i <= k; i++) 
//		for (int j = 0; j < n && v[j] <= i; j++) 
//			memo[i] = min(memo[i], memo[i - v[j]] + 1);
//		
//	printf("%d", memo[k] <= 10000 ? memo[k] : -1);
//
//	return 0;
//}

// top-down
//int go(int s, int cur) {
//	if (s == n) {
//		if (cur == 0)
//			return 0;
//		else 
//			return 10001;
//	}
//
//	int& res = memo[cur];
//	if (~res && res < 100000)
//		return res;
//	
//	res = 1e9;
//
//	for (int i = 0; v[s] * i <= cur; i++) {
//		res = min(res, go(s + 1, cur - v[s] * i) + i);
//	}
//
//	return res;
//}
//
//int main() {
//	scanf_s("%d %d", &n, &k);
//	v.resize(n);
//	memset(memo, -1, sizeof(memo));
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%d", &v[i]);
//
//	sort(v.begin(), v.end());
//	int ans = go(0, k);
//
//	if (ans > 10000) {
//		printf("-1");
//		return 0;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}