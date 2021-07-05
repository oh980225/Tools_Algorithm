#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1000];
int ind[1000];

void topologicalSort(int v) {
	queue<int> q;

	for (int i = 1; i <= v; ++i)
		if (ind[i] == 0)
			q.push(i);

	while (q.size()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			--ind[next];
			if (ind[next] == 0)
				q.push(next);
		}
	}
}