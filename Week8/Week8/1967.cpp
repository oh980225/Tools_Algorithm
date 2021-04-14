//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct EDGE {
//	int to, w;
//};
//
//vector<EDGE> node[10001];
//bool chk[10001];
//int dis[10001];
//
//void go(int s, int w) {
//	if (chk[s])
//		return;
//	chk[s] = 1;
//	dis[s] = w;
//
//	for (int i = 0; i < node[s].size(); i++) 
//		go(node[s][i].to, w + node[s][i].w);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n - 1; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		node[a].push_back({ b, c });
//		node[b].push_back({ a, c });
//	}
//
//	go(1, 0);
//
//	int ans = 0;
//	int ansI = 0;
//	for (int i = 1; i <= n; i++) {
//		if (dis[i] > ans) {
//			ans = dis[i];
//			ansI = i;
//		}
//	}
//
//	memset(chk, 0, sizeof(chk));
//	memset(dis, 0, sizeof(dis));
//	go(ansI, 0);
//	ans = 0;
//	for (int i = 1; i <= n; i++)
//		ans = max(ans, dis[i]);
//
//	printf("%d", ans);
//
//	return 0;
//}