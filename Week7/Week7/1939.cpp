//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct EDGE {
//	int to, w;
//};
//
//int n, m, s, f;
//vector<EDGE> graph[10001];
//
//bool chk(int num) {
//	int check[10001] = { 0 };
//	queue<EDGE> q;
//	q.push({ s, (int)1e9 });
//	check[s] = 1;
//	while (q.size()) {
//		int frontTo = q.front().to;
//		int frontW = q.front().w;
//		q.pop();
//
//		if (frontTo == f && frontW >= num) 
//			return 1;
//
//		for (int i = 0; i < graph[frontTo].size(); i++) {
//			int nt = graph[frontTo][i].to;
//			int nw = graph[frontTo][i].w;
//			if (!check[nt] && nw >= num) {
//				check[nt] = 1;
//				q.push({ nt, nw });
//			}
//		}
//	}
//	return 0;
//}
//
//int main() {
//	scanf_s("%d %d", &n, &m);
//
//	int l = 1e9;
//	int r = 0;
//	for (int i = 0; i < m; i++) {
//		int from, to, w;
//		scanf_s("%d %d %d", &from, &to, &w);
//		graph[from].push_back({ to, w });
//		graph[to].push_back({ from, w });
//		l = min(l, w);
//		r = max(r, w);
//	}
//
//	scanf_s("%d %d", &s, &f);
//
//	int ans = 0;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (chk(mid)) {
//			l = mid + 1;
//			ans = mid;
//		}
//		else
//			r = mid - 1;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}