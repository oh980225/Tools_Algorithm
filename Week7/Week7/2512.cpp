#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> seq;

bool chk(int mid) {
	int total = 0;
	for (auto element : seq) {
		if (mid < element)
			total += mid;
		else
			total += element;
	}
	if (total > m)
		return false;
	return true;
}

int main() {
	scanf_s("%d", &n);
	seq.resize(n);
	int total = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &seq[i]);
		total += seq[i];
	}

	sort(seq.begin(), seq.end());
	int l = 1;
	int r = seq[n - 1];

	scanf_s("%d", &m);

	if (total <= m) {
		printf("%d", r);
		return 0;
	}

	while (l <= r) {
		int mid = (l + r) / 2;
		if (chk(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}

	printf("%d", ans);
	
	return 0;
}