#include <bits/stdc++.h>

using namespace std;

int N, R, Q;
vector<int> adj[100001];
bool chk[100001];
int memo[100001];

int dfs(int x) {
  if(chk[x]) {
    return memo[x];
  }

  chk[x] = true;
  for(auto element : adj[x]) {
    if(!chk[element]) {
      memo[x] += dfs(element);
    }
  }

  return memo[x];
}

int main() {
  ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

  cin >> N >> R >> Q;

  for(int i = 1; i <= N; i++) {
    memo[i] = 1;
  }

  int U, V;
  for(int i = 0; i < N - 1; i++) {
    cin >> U >> V;
    adj[U].push_back(V);
    adj[V].push_back(U);
  }

  dfs(R);

  for(int i = 0; i < Q; i++) {
    cin >> U;
    cout << memo[U] << '\n';
  }

  return 0;
}