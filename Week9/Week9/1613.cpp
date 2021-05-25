#include <bits/stdc++.h>

using namespace std;

int n, k;

int matrix[401][401];

int main() {
	scanf("%d %d", &n, &k);
	int f, s;
	for (int i = 0; i < k; i++) { 
		scanf("%d %d", &f, &s);
		matrix[f][s] = -1;
		matrix[s][f] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k || k == i || j == i)
					continue;
				if (!matrix[j][k]) {
					if (matrix[j][i] == 1 && matrix[i][k] == 1) {
						matrix[j][k] = 1;
					}
					else if (matrix[j][i] == -1 && matrix[i][k] == -1) {
						matrix[j][k] = -1;
					}
				}
			}
		}
	}

	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d %d", &f, &s);
		printf("%d\n", matrix[f][s]);
	}
	

	return 0;
}