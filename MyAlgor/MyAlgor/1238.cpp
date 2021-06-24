#include <bits/stdc++.h>

using namespace std;

int road[1005][1005];
int n, m, x;

int main() {
	scanf_s("%d %d %d", &n, &m, &x);

	memset(road, 0x3f, sizeof(road));

	for (int i = 0; i < m; i++) {
		int s, e, t;
		scanf_s("%d %d %d", &s, &e, &t);
		road[s][e] = t;
	}

	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				if (road[i][j] > road[i][k] + road[k][j]) 
					road[i][j] = road[i][k] + road[k][j];

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		int tmp = road[i][x] + road[x][i];
		ans = max(ans, tmp);	
	}

	printf("%d", ans);

	return 0;
}