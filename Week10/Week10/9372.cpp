#include <bits/stdc++.h>

using namespace std;

int t, m, n;

int main() {
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &n, &m);
		int s, e;
		for (int j = 0; j < m; j++) {
			scanf_s("%d %d", &s, &e);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}