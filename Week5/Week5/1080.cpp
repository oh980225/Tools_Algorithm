#include <bits/stdc++.h>

using namespace std;

int matrix[2][51][51];
int ans;

void rev(int i, int j) {
	for (int y = i; y < i + 3; y++)
		for (int x = j; x < j + 3; x++)
			matrix[0][y][x] = 1 - matrix[0][y][x];

	ans++;
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < m; k++)
				scanf_s("%1d", &matrix[i][j][k]);
		
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (matrix[0][i][j] != matrix[1][i][j])
				rev(i, j);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matrix[0][i][j] != matrix[1][i][j])
				ans = -1;

	printf("%d", ans);

	return 0;
}