#include <bits/stdc++.h>

using namespace std;

int N, M, X;
vector<int> adj[100001];
bool chk[100001];
int ans;

int main() {
  cin >> N >> M;

  int from, to;
  for(int i = 0; i < M; i++) {
    cin >> from >> to;
    adj[to].push_back(from);
  }

  cin >> X;

  queue<int> q;
  q.push(X);
  chk[X] = true;

  while(q.size()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < adj[cur].size(); i++) { 
      if(!chk[adj[cur][i]]) {
        ans++;
        chk[adj[cur][i]] = true;
        q.push(adj[cur][i]);
      }
    }
  }

  cout << ans;

  return 0;
}