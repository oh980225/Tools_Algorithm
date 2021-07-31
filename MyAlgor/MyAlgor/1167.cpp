#include <bits/stdc++.h>

using namespace std;

struct EDGE {
	int to, w;
};

int chk[100005];
vector<EDGE> tree[100005];
int maxDis = 0;
int edge = 0;

void dfs(int s, int curDis) {
	chk[s] = 1;
	for (int i = 0; i < tree[s].size(); i++) {
		if (!chk[tree[s][i].to]) {
			chk[tree[s][i].to] = 1;
			if (maxDis < curDis + tree[s][i].w) {
				edge = tree[s][i].to;
				maxDis = curDis + tree[s][i].w;
			}
			dfs(tree[s][i].to, curDis + tree[s][i].w);
		}
	}
}

int main() {
	int v;
	scanf_s("%d", &v);

	for (int i = 0; i < v; i++) {
		int num;
		scanf_s("%d", &num);
		while (true) {
			int to;
			int w;
			scanf_s("%d", &to);
			if (to == -1)
				break;
			scanf_s("%d", &w);
			tree[num].push_back({ to, w });
		}
	}

	dfs(1, 0);
	int maxEdge = edge;
	memset(chk, 0, sizeof(chk));
	dfs(edge, 0);

	printf("%d", maxDis);

	return 0;
}