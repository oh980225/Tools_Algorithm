//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	int t;
//	scanf_s("%d", &t);
//
//	while (t--) {
//		priority_queue<ll> pq;
//
//		int n;
//		scanf_s("%d", &n);
//		ll ans = 0;
//
//		while (n--) {
//			ll num;
//			scanf_s("%lld", &num);
//			pq.push(-num);
//		}
//
//		while (pq.size() > 1) {
//			ll first = pq.top();
//			pq.pop();
//			ll second = pq.top();
//			pq.pop();
//			pq.push(first + second);
//			ans -= first + second;
//		}
//
//		printf("%lld\n", ans);
//	}
//
//	return 0;
//}