#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N, M;
struct EDGE {
  int to, w;
};
vector<EDGE> adj[100005];
bool chk[100005];
ll sum, minSum;
int result;

bool operator < (EDGE a, EDGE b) {
  return a.w > b.w;
}

void input() {
  cin >> N >> M;

  int to, from, cost;
  for(int i = 0; i < M; i++) {
    cin >> from >> to >> cost;
    adj[to].push_back({from, cost});
    adj[from].push_back({to, cost});
    sum += cost;
  }
}

bool notConnection() {
  for(int i = 1; i <= N; i++) 
    if(!chk[i]) 
      return true;
  return false;
}

void findMinRoad() {
  priority_queue<EDGE> pq;
  int firstIdx = 0;

  for(int i = 1; i <= N; i++) {
    if(adj[i].size()) {
      firstIdx = i;
      break;
    }
  }

  chk[firstIdx] = true;
  for(int i = 0; i < adj[firstIdx].size(); i++) 
    pq.push(adj[firstIdx][i]);

  while(pq.size()) {
    auto cur = pq.top();
    pq.pop();

    if(chk[cur.to]) 
      continue;

    chk[cur.to] = true;
    minSum += cur.w;

    for(int i = 0; i < adj[cur.to].size(); i++) 
      if(!chk[adj[cur.to][i].to]) 
        pq.push(adj[cur.to][i]);
  }
}

void output() {
  if(notConnection()) {
    cout << -1;  
    return;
  }
  cout << sum - minSum;
}

int main() {
  input();

  findMinRoad();

  output();

  return 0;
}