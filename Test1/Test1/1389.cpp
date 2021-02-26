//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int n, m, ans;
//
//vector<int> friends[101];
//vector<pair<int, int>> users;
//int check[101];
//
//int main() {
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int first;
//		int second;
//		cin >> first >> second;
//		friends[first].push_back(second);
//		friends[second].push_back(first);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		queue<int> q;
//		q.push(i);
//		check[i] = 1;
//		while (q.size()) {
//			int user = q.front();
//			q.pop();
//			for (auto element : friends[user]) {
//				if (!check[element]) {
//					check[element] += check[user] + 1;
//					ans += (check[element] - 1);
//					q.push(element);
//				}
//			}
//		}
//		users.push_back(pair<int, int>(ans, i));
//		ans = 0;
//		memset(check, 0, sizeof(check));
//	}
//
//	sort(users.begin(), users.end());
//
//	cout << users[0].second;
//
//	return 0;
//}