#include <bits/stdc++.h>

using namespace std;

int matrix[105][105];

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	memset(matrix, 0x3f, sizeof(matrix));

	for (int i = 0; i < m; i++) {
		int s, e, w;
		scanf_s("%d %d %d", &s, &e, &w);
		matrix[s][e] = min(w, matrix[s][e]);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (i == j)
					continue;
				int next = matrix[i][k] + matrix[k][j];
				if (matrix[i][j] > next) {
					matrix[i][j] = next;
				}
			}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == 1061109567) {
				matrix[i][j] = 0;
			}
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}