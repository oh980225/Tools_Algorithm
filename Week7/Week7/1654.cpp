//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll ans;
//vector<int> seq;
//int n, k;
//
//bool check(ll mid) {
//	int sum = 0;
//
//	for (auto element : seq) {
//		sum += element / mid;
//	}
//
//	if (sum >= n)
//		return true;
//
//	return false;
//}
//
//int main() {
//	scanf_s("%d", &k);
//	scanf_s("%d", &n);
//	seq.resize(k);
//
//	for (int i = 0; i < k; i++)
//		scanf_s("%d", &seq[i]);
//
//	ll l = 1;
//	ll r = 3e9;
//
//	while (l <= r) {
//		ll mid = (l + r) / 2;
//
//		if (check(mid)) {
//			l = mid + 1;
//			ans = mid;
//		}
//
//		else 
//			r = mid - 1;
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//}