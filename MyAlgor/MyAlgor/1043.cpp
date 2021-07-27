#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<int> dep;
vector<int> adj[55];

void init(int n) {
	p.resize(n + 1);
	dep.resize(n + 1);
	for (int i = 0; i < p.size(); i++) {
		p[i] = i;
		dep[i] = 0;
	}
	dep[0] = 1e9;
}

int Find(int x) {
	if (x == p[x])
		return p[x];
	return p[x] = Find(p[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (dep[x] < dep[y]) {
			p[x] = y;
		}
		else if (dep[y] < dep[x]) {
			p[y] = x;
		}
		else {
			++dep[x];
			p[y] = x;
		}
		return true;
	}
	return false;
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	int answer = m;
	init(n);

	int trueMan;
	scanf_s("%d", &trueMan);
	for (int i = 0; i < trueMan; i++) {
		int number;
		scanf_s("%d", &number);
		p[number] = 0;
	}

	for (int i = 1; i <= m; i++) {
		int number;
		scanf_s("%d", &number);
		if (number == 0)
			continue;
		int num;
		for (int j = 0; j < number; j++) {
			scanf_s("%d", &num);
			adj[i].push_back(num);
		}

		int pre = adj[i][0];
		for (int j = 1; j < adj[i].size(); j++) {
			Union(pre, adj[i][j]);
			pre = adj[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		if (adj[i].size() == 0)
			continue;
		if (Find(adj[i][0]) == 0)
			answer--;
	}
		

	printf("%d", answer);

	return 0;
}