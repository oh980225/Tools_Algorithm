#include <bits/stdc++.h>

using namespace std;

struct EDGE {
	int to, w;
};

vector<EDGE> v[805];
vector<int> res;
const int INF = 1e9;
int chk[805];
int n, e;

bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}

void func(int s) {
	fill(res.begin(), res.end(), INF);
	priority_queue<EDGE> pq;
	res[s] = 0;
	pq.push({ s, 0 });
	while (pq.size()) {
		auto curTo = pq.top().to;
		auto curW = pq.top().w;
		pq.pop();
		if (chk[curTo])
			continue;
		chk[curTo]++;
		for (auto el : v[curTo]) {
			if (res[el.to] > curW + el.w) {
				res[el.to] = curW + el.w;
				pq.push({ el.to, curW + el.w });
			}
		}
	}
	memset(chk, 0, sizeof(chk));

	return;
}

// 다익스트라를 3번 적용해서 해결
int main() {
	scanf_s("%d %d", &n, &e);
	res.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int num, to, w;
		scanf_s("%d %d %d", &num, &to, &w);
		v[num].push_back({ to, w });
		v[to].push_back({ num, w });
	}

	int key1, key2;
	scanf_s("%d %d", &key1, &key2);

	func(key1);
	int key1ToKey2 = res[key2];
	int key1ToEnd = res[n];

	func(1);
	int key1Dis = res[key1];
	int key2Dis = res[key2];

	func(key2);
	int key2ToEnd = res[n];

	int answer = 0;

	// overflow 조심
	if (key1Dis >= INF || key2Dis >= INF || key1ToEnd >= INF || key2ToEnd >= INF || key1ToKey2 >= INF) {
		printf("-1");
		return 0;
	}
	if (key2ToEnd + key1Dis > key1ToEnd + key2Dis) {
		if (key1ToEnd + key2Dis + key1ToKey2 >= INF) {
			printf("-1");
			return 0;
		}
		answer = key1ToEnd + key2Dis + key1ToKey2;
	}
	else {
		if (key2ToEnd + key1Dis + key1ToKey2 >= INF) {
			printf("-1");
			return 0;
		}
		answer = key2ToEnd + key1Dis + key1ToKey2;
	}

	printf("%d", answer);

	return 0;
}