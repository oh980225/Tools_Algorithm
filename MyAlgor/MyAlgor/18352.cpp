#include<bits/stdc++.h>

using namespace std;

struct EDGE {
	int to, w;
};

vector<EDGE> adj[300001];
int N, M, K, X;

bool operator < (EDGE e1, EDGE e2) {
	return e1.w > e2.w;
}

vector<int> Dijkstra(int st, int v) {
	vector<int> ans(v + 1);
	vector<int> chk(v + 1);

	fill(ans.begin(), ans.end(), 1e9);

	priority_queue<EDGE> q;
	q.push({ st, 0 });
	ans[st] = 0;

	while (q.size()) {
		auto cur = q.top(); q.pop();
		int x = cur.to, w = cur.w;

		if (chk[x]) {
      continue;
    }
		chk[x] = 1;

		for (auto nx : adj[x]) {
			if (ans[nx.to] > w + nx.w) {
				ans[nx.to] = w + nx.w;
				q.push({ nx.to, w + nx.w });
			}
		}
	}

	return ans;
}

int main() {
  cin >> N >> M >> K >> X;

  int from, to;
  for(int i = 0; i < M; i++) {
    cin >> from >> to;
    adj[from].push_back({to, 1});
  }

  vector<int> result = Dijkstra(X, N);
  bool flag = false;

  for(int i = 1; i < result.size(); i++) {
    if(result[i] == K) {
      flag = true;
      cout << i << '\n';    
    }
  }

  if(!flag) {
    cout << -1;
  }

  return 0;
}