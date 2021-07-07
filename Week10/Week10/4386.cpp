#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct EDGE {
	ll to, w;
};

vector<EDGE> adj[105];
bool check[105];
vector<pair<int, int>> pos;
int n;

ll getDis(int i, int j) {
	return pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2);
}

bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf_s("%lf %lf", &x, &y);
		pos.push_back(make_pair(x * 100, y * 100));
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			adj[i + 1].push_back({ j + 1, getDis(i, j) });
			adj[j + 1].push_back({ i + 1, getDis(j, i) });
		}
	}

	priority_queue<EDGE> pq;
	double ans = 0;
	check[1] = 1;
	for (int i = 0; i < adj[1].size(); i++) {
		pq.push({ adj[1][i].to, adj[1][i].w });
	}
	while (pq.size()) {
		auto cur = pq.top();
		pq.pop();

		if (check[cur.to])
			continue;

		check[cur.to] = 1;
		ans += sqrt(cur.w);
		for (int i = 0; i < adj[cur.to].size(); i++) 
			if(!check[adj[cur.to][i].to])
				pq.push({ adj[cur.to][i].to, adj[cur.to][i].w });
	}

	printf("%.2lf", ans / 100.0);

	return 0;
}