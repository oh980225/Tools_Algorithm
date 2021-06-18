#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);

	vector<int> v(n + 1);

	int l = 0;
	int r = n - 1;

	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);

	int sum = abs(v[0] + v[n - 1]);
	int resultL = l;
	int resultR = r;

	while (l < r) {
		int tmp = v[l] + v[r];

		if (sum > abs(tmp)) {
			sum = abs(tmp);
			resultL = l;
			resultR = r;
		}

		if (tmp < 0) {
			l++;
		}
		else if (tmp == 0) {
			break;
		}
		else {
			r--;
		}
	}

	printf("%d %d", v[resultL], v[resultR]);

	return 0;
}