#include <bits/stdc++.h>

using namespace std;

vector<int> v[32005];
int ind[32005];

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		v[a].push_back(b);
		ind[b]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (!ind[i])
			pq.push((-1) * i);
	}

	while (pq.size()) {
		int cur = (-1) * pq.top();
		pq.pop();
		printf("%d ", cur);
		for (int i = 0; i < v[cur].size(); i++) {
			ind[v[cur][i]]--;
			if (!ind[v[cur][i]])
				pq.push((-1) * v[cur][i]);
		}
	}

	return 0;
}