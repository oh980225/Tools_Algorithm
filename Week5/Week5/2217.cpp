//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	int n;
//	ll ans = 0;
//	scanf_s("%d", &n);
//	vector<ll> v(n);
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%lld", &v[i]);
//
//	sort(v.begin(), v.end());
//	reverse(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++) {
//		ans = max(ans, (i + 1) * v[i]);
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//}