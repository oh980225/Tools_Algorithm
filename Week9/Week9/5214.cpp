//#include<bits/stdc++.h>
//using namespace std;
//vector<int> hyper[1010];
//vector<int> adj[101010];
//bool chk[101010]; // 역 방문
//bool chkHyper[1010]; // 하이퍼 방문
//typedef tuple<int, int, bool> T;
//int main() {
//	int n, k, m;
//	cin >> n >> k >> m;
//	priority_queue<T, vector<T>, greater<T>> q;
//	for (int i = 0; i < m; ++i) {
//		hyper[i].resize(k);
//		for (int j = 0; j < k; ++j) {
//			cin >> hyper[i][j];
//			adj[hyper[i][j]].push_back(i);
//			if (hyper[i][j] == 1) {
//				q.push({ 1, i, 1 });
//				chkHyper[i] = 1;
//			}
//		}
//	}
//	if (n == 1) {
//		printf("1"); return 0;
//	}
//	while (q.size()) {
//		int cur, d; bool isHyper;
//		tie(d, cur, isHyper) = q.top(); q.pop();
//		if (isHyper) {
//			for (int i = 0; i < hyper[cur].size(); ++i) { // 여기서의 cur은 해당 역이 속한 hyper
//				if (!chk[hyper[cur][i]]) {
//					chk[hyper[cur][i]] = 1;
//					q.push({ d + 1, hyper[cur][i], 0 }); // 동일 hyper내에 역 이동이기에 d + 1
//				}
//			}
//		}
//		else {
//			if (n == cur) {
//				cout << d;
//				return 0;
//			}
//			for (int i = 0; i < adj[cur].size(); ++i) { // 여기서의 cur은 해당 hyper에 속한 역
//				if (!chkHyper[adj[cur][i]]) {
//					chk[chkHyper[adj[cur][i]]] = 1;
//					q.push({ d, adj[cur][i], 1 }); // hyper간 이동이기에 d 그대로
//				}
//			}
//		}
//	}
//	cout << "-1";
//}