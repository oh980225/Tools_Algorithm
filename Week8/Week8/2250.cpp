//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<int> node[10001];
//vector<int> level[20];
//int col;
//
//void go(int s, int h) {
//	if (s == -1)
//		return;
//	go(node[s][0], h + 1);
//	level[h].push_back(col++);
//	go(node[s][1], h + 1);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int parent[10001] = { 0 };
//
//	for (int i = 0; i < n; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		node[a].push_back(b);
//		node[a].push_back(c);
//		if (b != -1)
//			parent[b] = a;
//		if (c != -1)
//			parent[c] = a;
//	}
//
//	int root = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!parent[i]) {
//			root = i;
//			break;
//		}
//	}
//
//	go(root, 1);
//	int ans = 0;
//	int ansI = 0;
//	for (int i = 1; i < 20; i++) {
//		if (level[i].size() > 1) {
//			if (level[i].back() - level[i][0] + 1 > ans) {
//				ans = level[i].back() - level[i][0] + 1;
//				ansI = i;
//			}
//		}
//		else if (level[i].size()) {
//			if (ans < 1) {
//				ans = 1;
//				ansI = i;
//			}
//		}
//	}
//
//	printf("%d %d", ansI, ans);
//
//	return 0;
//}