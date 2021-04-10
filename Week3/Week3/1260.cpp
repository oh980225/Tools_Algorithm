#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
int chk[1001];
int n, m, v;

void dfs(int s) {
	chk[s] = 1;
	printf("%d ", s);
	sort(graph[s].begin(), graph[s].end());
	for (int i = 0; i < graph[s].size(); i++) {
		if (!chk[graph[s][i]]) {
			dfs(graph[s][i]);
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	chk[s] = 1;
	while (q.size()) {
		int f = q.front();
		printf("%d ", f);
		q.pop();
		sort(graph[f].begin(), graph[f].end());
		for (int i = 0; i < graph[f].size(); i++) {
			if (!chk[graph[f][i]]) {
				chk[graph[f][i]] = chk[f] + 1;
				q.push(graph[f][i]);
			}
		}
	}
}

int main() {
	scanf_s("%d %d %d", &n, &m, &v);
	int s, e;
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &s, &e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	dfs(v);
	memset(chk, 0, sizeof(chk));
	puts("");
	bfs(v);

	return 0;
}