#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct EDGE {
	ll to, w, c;
};

vector<EDGE> road[4005];
int arr[4005];

bool operator < (EDGE a, EDGE b) {
	return a.w > b.w;
}

vector<ll> func1(int st, int v) {
	vector<ll> ans(v + 1);
	vector<int> chk(v + 1);
	fill(ans.begin(), ans.end(), 1e16);
	priority_queue<EDGE> pq;
	pq.push({ st, 0 });
	ans[st] = 0;
	while (pq.size()) {
		auto f = pq.top();
		int curTo = f.to;
		auto curW = f.w;
		pq.pop();
		if (chk[curTo])
			continue;
		chk[curTo] = 1;
		for (auto el : road[curTo]) {
			if (ans[el.to] > f.w + el.w) {
				ans[el.to] = f.w + el.w;
				pq.push({ el.to, ans[el.to] });
			}
		}
	}
	return ans;
}

vector<ll> func2(int st, int v) {
	bool chk[4005][2] = { 0 };
	vector<ll> ans(v + 1);
	fill(ans.begin(), ans.end(), 1e16);
	priority_queue<EDGE> pq;
	pq.push({ st, 0, 0 });
	ans[st] = 0;
	while (pq.size()) {
		auto f = pq.top();
		auto curTo = f.to;
		auto curW = f.w;
		auto curC = f.c;
		pq.pop();
		if (chk[curTo][curC % 2])
			continue;
		chk[curTo][curC % 2] = 1;
		for (auto el : road[curTo]) {
			int nd = 0;
			if (curC % 2)
				nd = el.w * 2;
			else
				nd = el.w / 2;
			if (ans[el.to] > curW + nd) {
				ans[el.to] = curW + nd;
			}
			pq.push({ el.to, curW + nd, curC + 1 });
		}
	}
	return ans;
}

int main() {
	int n, m, a, b, d;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &d);
		road[a].push_back({ b, d * 10, 0 });
		road[b].push_back({ a, d * 10, 0 });
	}

	vector<ll> ansFox = func1(1, n);
	vector<ll> ansWolf = func2(1, n);
	int answer = 0;

	for (int i = 2; i <= n; i++) {
		if (ansWolf[i] > ansFox[i])
			answer++;
	}

	printf("%d", answer);

	return 0;
}