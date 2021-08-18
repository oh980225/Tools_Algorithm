#include <bits/stdc++.h>

using namespace std;

struct EDGE {
	int to, w;
};

bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}

vector<EDGE> road[100005];
bool chk[100005];

int prim(vector<EDGE> &ans, int v) {
	int sum = 0;
	priority_queue<EDGE> pq;
	chk[v] = 1;

	for (int i = 0; i < road[v].size(); i++) {
		pq.push(road[v][i]);
	}

	while (pq.size()) {
		int curTo = pq.top().to;
		int curW = pq.top().w;
		pq.pop();

		if (chk[curTo])
			continue;

		ans.push_back({ curTo, curW });
		chk[curTo] = 1;
		sum += curW;
		for (int i = 0; i < road[curTo].size(); i++) 
			if(!chk[road[curTo][i].to])
				pq.push(road[curTo][i]);
	}

	return sum;
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int from, to, w;
		scanf_s("%d %d %d", &from, &to, &w);
		road[from].push_back({ to, w });
		road[to].push_back({ from, w });
	}
	
	vector<EDGE> ans;
	int result = prim(ans, 1);

	int maxW = 0;
	for (auto element : ans) {
		if (maxW < element.w)
			maxW = element.w;
	}

	printf("%d", result - maxW);

	return 0;
}