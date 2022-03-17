#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[10001];
int memo[10001][2];
bool chk[10001];

void dfs(int x) {
  for(auto element : adj[x]) {
    if(!chk[element]) {
      chk[element] = true;
      dfs(element);
      memo[x][0] += max(memo[element][0], memo[element][1]);
      memo[x][1] += memo[element][0];
    }
  }
}

int main() {
  cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> memo[i][1];
    memo[i][0] = 0;
  }

  int from, to;
  for(int i = 0; i < N - 1; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  chk[1] = true;
  dfs(1);

  cout << max(memo[1][0], memo[1][1]);

  return 0;
}