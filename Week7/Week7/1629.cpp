//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll pow(ll a, ll b, ll c) {
//	if (b <= 0)
//		return 1 % c;
//	if (b == 1)
//		return a % c;
//	if (b % 2)
//		return ((a % c) * pow(a, b - 1, c) % c) % c;
//	else {
//		ll res = pow(a, b / 2, c) % c;
//		return res * res % c;
//	}
//}
//
//int main() {
//	ll a, b, c;
//	scanf_s("%lld %lld %lld", &a, &b, &c);
//
//	printf("%lld", pow(a, b, c));
//
//	return 0;
//}