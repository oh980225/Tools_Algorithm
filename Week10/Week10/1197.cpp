#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> root;
vector<int> dep;
struct EDGE {
	ll from, to, w;
};
vector<EDGE> edges;

void init(int v) {
	root.resize(v + 1);
	dep.resize(v + 1);
	for (int i = 0; i < root.size(); i++) {
		root[i] = i;
		dep[i] = 0;
	}
}

int Find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = Find(root[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (dep[x] < dep[y]) {
			root[x] = y;
		}
		else if (dep[y] < dep[x]) {
			root[y] = x;
		}
		else {
			++dep[x];
			root[y] = x;
		}
		return true;
	}
	return false;
}

int main() {
	int v, e;
	scanf_s("%d %d", &v, &e);
	int to, from, w;
	for (int i = 0; i < e; i++) {
		scanf_s("%d %d %d", &from, &to, &w);
		edges.push_back({ from, to, w });
		edges.push_back({ to, from, w });
	}

	ll ans = 0;

	sort(edges.begin(), edges.end(), [](EDGE e1, EDGE e2) {
		return e1.w < e2.w;
	});

	init(v);

	for (int i = 0; i < edges.size(); i++) {
		if (Union(edges[i].from, edges[i].to)) {
			ans += edges[i].w;
		}
	}

	printf("%lld", ans);
	return 0;
}