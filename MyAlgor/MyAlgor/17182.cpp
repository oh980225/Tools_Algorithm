#include <bits/stdc++.h>

using namespace std;

int matrix[11][11];
int chk[1 << 11][11];

struct EDGE {
	int num, check, time;
};

bool operator < (EDGE e1, EDGE e2) {
	return e1.time > e2.time;
}

// 다익스트라 + 비트마스트
int main() {
	int n, k;
	memset(chk, 0x3f, sizeof(chk));
	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf_s("%d", &matrix[i][j]);

	int answer = 0;
	priority_queue<EDGE> pq;
	pq.push({ k, 1 << k, 0 });
	while (pq.size()) {
		auto num = pq.top().num;
		auto check = pq.top().check;
		auto time = pq.top().time;
		pq.pop();
		if (check == (1 << n) - 1) {
			answer = time;
			break;
		}
		for (int i = 0; i < n; i++) {
			if (i == num)
				continue;
			if (time + matrix[num][i] < chk[check][i]) {
				chk[check][i] = time + matrix[num][i];
				pq.push({ i, check | (1 << i), chk[check][i] });
			}
		}
	}

	printf("%d", answer);

	return 0;
}