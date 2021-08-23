#include <bits/stdc++.h>

using namespace std;

class UnionFind {
	vector<int> p;
	vector<int> dep;

public:
	void init(int n) {
		p.resize(n + 1);
		dep.resize(n + 1);
		for (int i = 0; i < p.size(); i++) {
			p[i] = i;
			dep[i] = 0;
		}
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
};

struct EDGE {
	int from, to;
};

vector<EDGE> edge;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		edge.push_back({ from, to });
	}
	
	int ans = 0;
	UnionFind uf;
	uf.init(n);

	for (int i = 0; i < edge.size(); i++) {
		ans++;
		if (!uf.Union(edge[i].from, edge[i].to)) {
			cout << ans;
			return 0;
		}
	}

	cout << 0;

	return 0;
}