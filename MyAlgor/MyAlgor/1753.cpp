#include <bits/stdc++.h>

using namespace std;

// Dijkstra algorithm

struct EDGE {
	int to, w;
};

bool operator < (EDGE a, EDGE b) {
	return a.w > b.w;
}

vector<EDGE> graph[20005];

int main() {
	int v, e;
	scanf_s("%d %d", &v, &e);

	int start;
	scanf_s("%d", &start);

	for (int i = 0; i < e; i++) {
		int from, to, w;
		scanf_s("%d %d %d", &from, &to, &w);
		graph[from].push_back({to, w});
	}

	vector<int> ans(v + 1);
	vector<int> chk(v + 1);
	fill(ans.begin(), ans.end(), 1e9);

	priority_queue<EDGE> pq;
	pq.push({ start, 0 });
	ans[start] = 0;

	while (pq.size()) {
		auto f = pq.top();
		pq.pop();
		if (chk[f.to])
			continue;
		chk[f.to]++;
		for (auto next : graph[f.to]) {
			if (ans[next.to] > next.w + f.w) {
				ans[next.to] = next.w + f.w;
				pq.push({ next.to, next.w + f.w });
			}
		}
	}

	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] == 1e9) {
			printf("INF\n");
		}
		else {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}