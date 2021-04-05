//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, c;
//vector<int> seq;
//int ans;
//
//bool chk(int mid) {
//	int f = seq[0];
//	int cnt = 1;
//	for (auto element : seq) {
//		if (f + mid <= element) {
//			f = element;
//			cnt++;
//		}
//	}
//
//	if (c <= cnt) {
//		return true;
//	}
//
//	return false;
//}
//
//int main() {
//	scanf_s("%d %d", &n, &c);
//	seq.resize(n);
//
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &seq[i]);
//	}
//
//	sort(seq.begin(), seq.end());
//
//	int l = 1;
//	int r = seq[n - 1] - seq[0];
//
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (chk(mid)) {
//			ans = max(ans, mid);
//			l = mid + 1;
//		}
//		else 
//			r = mid - 1;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}