#include <bits/stdc++.h>

using namespace std;

int N;

int ind[10005];
int needCost[10005];
int memo[10005];
vector<int> adj[10005];

void input() {
  cin >> N;

  int cost, cnt;
  for(int i = 1; i <= N; i++) {
    cin >> cost >> cnt;

    ind[i] = cnt;
    needCost[i] = cost;

    int needFirstNum;
    for(int j = 0; j < cnt; j++) {
      cin >> needFirstNum;
      adj[needFirstNum].push_back(i);
    }
  }
}

void topological() {
  queue<int> q;
  for(int i = 1; i <= N; i++) {
    if(!ind[i]) {
      q.push(i);
      memo[i] = needCost[i];
    }
  }

  while(q.size()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i];
      memo[next] = max(memo[next], memo[cur] + needCost[next]);
      --ind[next];
      if(!ind[next]) {
        q.push(next);
      }
    }
  }
}

int main() {
  input();

  topological();

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans = max(ans, memo[i]);
  }

  cout << ans;

  return 0;
}