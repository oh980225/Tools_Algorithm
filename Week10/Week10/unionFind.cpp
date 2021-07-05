#include <bits/stdc++.h>

using namespace std;

class UnionFind {
	vector<int> p;
	vector<int> dep;

	void init(int n) {
		p.resize(n + 1);
		dep.resize(n + 1);
		for (int i = 0; i < p.size(); i++) {
			p[i] = i;
			dep[i] = 0;
		}
	}

	//// 시간 복잡도 O(N)
	//int Find(int x) {
	//	if (x == p[x])
	//		return p[x];
	//	return Find(p[x]);
	//}

	//// 시간 복잡도 O(N)
	//bool Union(int x, int y) {
	//	x = Find(x);
	//	y = Find(y);
	//	if (x != y) {
	//		p[y] = x;
	//		return true;
	//	}
	//	return false;
	//}

	// 시간 복잡도 O(log N)
	int Find(int x) {
		if (x == p[x])
			return p[x];
		return p[x] = Find(p[x]);
	}

	// 시간 복잡도 O(log N)
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