#include <bits/stdc++.h>

using namespace std;

int ans, n;
vector<int> v;
int chk[10];

void go(int pre, int sum, int cnt) {
	if (cnt == n - 1) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			go(v[i], sum + abs(pre - v[i]), cnt + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	scanf_s("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);

	for (int i = 0; i < n; i++) {
		chk[i] = 1;
		go(v[i], 0, 0);
		chk[i] = 0;
	}
	
	printf("%d", ans);

	return 0;
}