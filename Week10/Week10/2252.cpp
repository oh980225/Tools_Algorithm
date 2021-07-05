#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32005];
int ind[32005];

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	int from, to;
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &from, &to);
		adj[from].push_back(to);
		ind[to]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)
			q.push(i);
	}

	while (q.size()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			ind[adj[cur][i]]--;
			if (ind[adj[cur][i]] == 0) 
				q.push(adj[cur][i]);
		}
	}

	return 0;
}