//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll a, b, v;
//
//bool chk(ll day) {
//	return a * day - b * (day - 1) >= v;
//}
//
//int main() {
//	scanf_s("%lld %lld %lld", &a, &b, &v);
//
//	ll l = 1;
//	ll r = 3e9;
//	ll ans = 3e9;
//
//	while (l <= r) {
//		ll mid = (l + r) / 2;
//		if (chk(mid)) {
//			r = mid - 1;
//			ans = min(ans, mid);
//		}
//		else
//			l = mid + 1;
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//}