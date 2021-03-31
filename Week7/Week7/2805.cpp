#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

vector<ll> seq;

bool check(ll mid) {
	ll sum = 0;
	for (auto element : seq) {
		if (element > mid)
			sum += element - mid;
	}

	if (sum >= m)
		return true;

	return false;
}

int main() {
	scanf_s("%lld", &n);
	scanf_s("%lld", &m);
	seq.resize(n);
	
	ll l = 0;
	ll r = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%lld", &seq[i]);
		r = max(seq[i], r);
	}

	ll ans = 0;

	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	printf("%lld", ans);

	return 0;
}