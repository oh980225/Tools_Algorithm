#include <bits/stdc++.h>

using namespace std;

class UnionFind {
	vector<int> p;
	vector<int> dep;

public : 
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
	int from, to, w;
};

vector<EDGE> edge;

int kruskal(vector<EDGE>& ans, int v) {
	int wSum = 0;

	sort(edge.begin(), edge.end(), [](EDGE e1, EDGE e2) {
		return e1.w < e2.w;
	});

	UnionFind d;
	d.init(v);

	for (int i = 0; i < edge.size(); ++i) {
		if (d.Union(edge[i].from, edge[i].to)) {
			wSum += edge[i].w;
			ans.push_back(edge[i]);
		}
	}

	return wSum;
}