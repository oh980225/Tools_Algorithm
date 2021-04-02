#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
	scanf_s("%d %d %d", &n, &a, &b);
	int ans = 0;
	while (a != b) {
		a -= a / 2;
		b -= b / 2;
		ans++;
	}

	printf("%d", ans);

	return 0;
}