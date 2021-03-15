#include <bits/stdc++.h>

using namespace std;

int memo[10001];

int main() {
	int n, k;

	scanf_s("%d %d", &n, &k);

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);

	memo[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = v[i]; j <= k; j++)
			memo[j] += memo[j - v[i]];

	printf("%d", memo[k]);

	return 0;
}