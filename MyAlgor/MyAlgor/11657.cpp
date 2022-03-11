#include <bits/stdc++.h>

using namespace std;

int N, M;

typedef long long ll;

struct EDGE {
  int from, to, w;
};

vector<EDGE> edges;

vector<ll> bellman(int v, int st) {
  vector<ll> ans;
  ans.resize(v + 1);
  fill(ans.begin(), ans.end(), INT_MAX);
  ans[st] = 0;

  for(int i = 1; i <= v; i++) {
    for(int j = 0; j < edges.size(); j++) {
      auto cur = edges[j];
      if(ans[cur.from] != INT_MAX && (ans[cur.to] > ans[cur.from] + cur.w)) {
        if(i == v) {
          ans[0] = -1;
          return ans;
        }
        ans[cur.to] = ans[cur.from] + cur.w;
      }
    }
  }

  return ans;
}


int main() {
  cin >> N >> M;

  int from, to, w;
  for(int i = 0; i < M; i++) {
    cin >> from >> to >> w;
    edges.push_back({from, to, w});
  }

  vector<ll> result = bellman(N, 1);

  if(result[0] == -1) {
    cout << -1 << '\n';
    return 0;
  }

  for(int i = 2; i <= N; i++) {
    if(result[i] == INT_MAX) {
      cout << -1 << '\n';
      continue;
    }
    cout << result[i] << '\n';
  }

  return 0;
}