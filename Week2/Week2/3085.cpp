#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> matrix;
int ans;

void func() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (matrix[i][j] == matrix[i][j + 1])
				cnt++;
			else {
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (matrix[j][i] == matrix[j + 1][i])
				cnt++;
			else {
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	ans = max(result, ans);
	return;
}

int main() {
	scanf_s("%d", &n);
	matrix.resize(n);

	for (int i = 0; i < n; i++) 
		cin >> matrix[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(matrix[i][j], matrix[i][j + 1]);
			func();
			swap(matrix[i][j], matrix[i][j + 1]);
			swap(matrix[j][i], matrix[j + 1][i]);
			func();
			swap(matrix[j][i], matrix[j + 1][i]);
		}
	}

	printf("%d", ans);

	return 0;
}