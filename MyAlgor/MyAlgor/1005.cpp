#include <bits/stdc++.h>

using namespace std;

int timeArr[1005];
vector<int> v[1005];
int ind[1005];
int memo[1005];

void topologicalSort(int n) {
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0) {
			q.push(i);
			memo[i] = timeArr[i];
		}
	}

	while (q.size()) {
		int cur = q.front(); 
		q.pop();

		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i];
			memo[next] = max(memo[next], timeArr[next] + memo[cur]);
			--ind[next];
			if (ind[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, k;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		for (int j = 1; j <= n; j++) {
			cin >> timeArr[j];
		}

		int from, to;
		for (int j = 0; j < k; j++) {
			cin >> from >> to;
			v[from].push_back(to);
			ind[to]++;
		}

		for (int j = 1; j <= n; j++) {
			if (ind[j] == 0)
				memo[j] = timeArr[j];
		}

		topologicalSort(n);

		int w;
		cin >> w;
		cout << memo[w] << "\n";

		memset(ind, 0, sizeof(ind));
		memset(timeArr, 0, sizeof(timeArr));
		memset(memo, 0, sizeof(memo));
		for (int j = 1; j <= n; j++) {
			v[j].clear();
		}
	}

	return 0;
}