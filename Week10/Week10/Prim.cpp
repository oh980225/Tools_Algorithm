#include <bits/stdc++.h>

using namespace std;

struct EDGE {
	int to, w;
};

vector<EDGE> adj[101010];
bool chk[101010];

bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}

int prim(vector<EDGE>& ans, int v) {
	int wSum = 0;
	priority_queue<EDGE> pq;
	chk[1] = 1;

	for (int i = 0; i < adj[1].size(); ++i)
		pq.push(adj[1][i]);

	while (pq.size()) {
		int curTo = pq.top().to;
		int curW = pq.top().w;
		pq.pop();

		if (chk[curTo]) 
			continue;

		chk[curTo] = 1;
		wSum += curW;
		ans.push_back({ curTo, curW });

		for (int i = 0; i < adj[curTo].size(); ++i)
			if (!chk[adj[curTo][i].to])
				pq.push(adj[curTo][i]);
	}

	return wSum;
}