//#include <bits/stdc++.h>
//
//using namespace std;
//
//int ans, n, m;
//bool chk[105];
//vector<int> grp[105];
//
//void bfs(int n) {
//	queue<int> q;
//	chk[n] = true;
//	for (auto element : grp[n]) {
//		if (!chk[element]) {
//			chk[element] = true;
//			q.push(element);
//		}
//	}
//
//	while (q.size()) {
//		int f = q.front();
//		ans++;
//		q.pop();
//		for (auto element : grp[f]) {
//			if (!chk[element]) {
//				chk[element] = true;
//				q.push(element);
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	cin >> m;
//	
//	int f, s;
//	for (int i = 0; i < m; i++) {
//		cin >> f >> s;
//		grp[f].push_back(s);
//		grp[s].push_back(f);
//	}
//
//	bfs(1);
//
//	cout << ans;
//
//	return 0;
//}