//#include<bits/stdc++.h>
//using namespace std;
//struct EDGE {
//	int to, w;
//};
//
//vector<EDGE> adj[101010];
//
//bool operator < (EDGE e1, EDGE e2) {
//	return e1.w > e2.w;
//}
//
//vector<int> Dijkstra(int st, int v) {
//	vector<int> ans(v + 1);
//	vector<int> chk(v + 1);
//	fill(ans.begin(), ans.end(), 1e9);
//	priority_queue<EDGE> q;
//	q.push({ st, 0 });
//	ans[st] = 0;
//	while (q.size()) {
//		auto cur = q.top(); q.pop();
//		int x = cur.to, w = cur.w;
//		if (chk[x]) continue;
//		chk[x] = 1;
//		for (auto nx : adj[x]) {
//			if (ans[nx.to] > w + nx.w) {
//				ans[nx.to] = w + nx.w;
//				q.push({ nx.to, w + nx.w });
//			}
//		}
//	}
//	return ans;
//}
//
//int main() {
//	adj[0].push_back({ 1, 2 });
//	adj[0].push_back({ 2, 3 });
//	adj[0].push_back({ 3, 6 });
//	adj[1].push_back({ 0, 2 });
//	adj[1].push_back({ 3, 3 });
//	adj[1].push_back({ 5, 7 });
//	adj[2].push_back({ 0, 3 });
//	adj[2].push_back({ 3, 1 });
//	adj[2].push_back({ 4, 2 });
//	adj[3].push_back({ 0, 6 });
//	adj[3].push_back({ 1, 3 });
//	adj[3].push_back({ 5, 1 });
//	adj[3].push_back({ 4, 3 });
//	adj[4].push_back({ 2, 2 });
//	adj[4].push_back({ 3, 3 });
//	adj[4].push_back({ 6, 5 });
//	adj[5].push_back({ 1, 7 });
//	adj[5].push_back({ 3, 1 });
//	adj[5].push_back({ 6, 1 });
//	adj[6].push_back({ 5, 1 });
//	adj[5].push_back({ 4, 5 });
//
//	vector<int> answer = Dijkstra(0, 6);
//
//	int i = 0;
//	for (auto element : answer) {
//		cout << i++ << ": ";
//		cout << element << endl;
//	}
//
//	return 0;
//}