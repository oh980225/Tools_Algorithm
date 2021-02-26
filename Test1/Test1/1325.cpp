//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//vector<int> graph[10001];
//int check[10001];
//int hack[10001];
//
//int n, m, ans;
//
//void dfs(int node) {
//	hack[node]++;
//	check[node]++;
//
//	ans = max(ans, hack[node]);
//
//	for (int i = 0; i < graph[node].size(); i++) {
//		if (!check[graph[node][i]]) {
//			dfs(graph[node][i]);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int first;
//		int second;
//		cin >> first >> second;
//		graph[first].push_back(second);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		dfs(i);
//		memset(check, 0, sizeof(check));
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (ans == hack[i]) {
//			cout << i << " ";
//		}
//	}
//	
//	return 0;
//}