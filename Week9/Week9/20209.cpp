//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, k;
//vector<int> sw[8];
//vector<int> cube;
//
//bool check(vector<int>& v) {
//	int f = v[0];
//	for (auto element : v) 
//		if (element != f)
//			return false;
//	return true;
//}
//
//vector<int> click(vector<int>& v, int num) {
//	vector<int> temp = v;
//	for (auto element : sw[num]) {
//		temp[element - 1] += (num + 1);
//		temp[element - 1] %= 5;
//	}
//	return temp;
//}
//
//int bfs() {
//	map<vector<int>, int> m;
//	queue<vector<int>> q;
//
//	m[cube] = 0;
//	q.push(cube);
//
//	while (q.size()) {
//		auto f = q.front();
//		q.pop();
//
//		int cnt = m[f];
//
//		if (check(f))
//			return cnt;
//
//		for (int i = 0; i < k; i++) {
//			vector<int> temp = click(f, i);
//			if (m.find(temp) == m.end()) {
//				m[temp] = cnt + 1;
//				q.push(temp);
//			}
//		}
//	}
//	return -1;
//}
//
//int main() {
//	cin >> n >> k;
//	cube.resize(n);
//
//	for (int i = 0; i < n; i++)
//		cin >> cube[i];
//
//	for (int i = 0; i < k; i++) {
//		int num;
//		cin >> num;
//		sw[i].resize(num);
//		for (int j = 0; j < num; j++) {
//			cin >> sw[i][j];
//		}
//	}
//
//	cout << bfs();
//	
//	return 0;
//}