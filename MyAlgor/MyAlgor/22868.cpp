#include <bits/stdc++.h>

using namespace std;

int N, M, S, E;

vector<int> adj[10001];
priority_queue<int, vector<int>, greater<int>> pq[10001];
bool chk[10001];
int ans;

struct PATH {
  int dist;
  vector<int> points;
};

void SToE() {
  PATH minPath;
  queue<PATH> q;
  q.push({0, {S}});
  chk[S] = true;

  while(q.size()) {
    auto cur = q.front();
    int curEndPoint = cur.points[cur.points.size() - 1];
    q.pop();

    // E에 도착했으면 종료
    if(curEndPoint == E) {
      minPath = cur;
      break;
    }

    while(pq[curEndPoint].size()) {
      int top = pq[curEndPoint].top();
      pq[curEndPoint].pop();

      if(!chk[top]) {
        chk[top] = true;
        vector<int> newPoints = cur.points;
        newPoints.push_back(top);
        q.push({cur.dist + 1, newPoints});
      }
    }
  }

  memset(chk, 0, sizeof(chk));

  // ans에 거리 추가
  ans += minPath.dist;

  // S -> E까지 가는 경로 체크
  for(auto element : minPath.points) {
    if(element == S || element == E)
      continue;
    
    chk[element] = true;
  }
}

void EToS() {
  PATH minPath;
  queue<PATH> q;
  q.push({0, {E}});
  chk[E] = true;

  while(q.size()) {
    auto cur = q.front();
    int curEndPoint = cur.points[cur.points.size() - 1];
    q.pop();

    // E에 도착했으면 종료
    if(curEndPoint == S) {
      minPath = cur;
      break;
    }

    for(int i = 0; i < adj[curEndPoint].size(); i++) {
      if(!chk[adj[curEndPoint][i]]) {
        chk[adj[curEndPoint][i]] = true;
        vector<int> newPoints = cur.points;
        newPoints.push_back(adj[curEndPoint][i]);
        q.push({cur.dist + 1, newPoints});
      }
    }
  }

  // ans에 거리 추가
  ans += minPath.dist;
}

int main() {
  cin >> N >> M;

  int from, to;
  for(int i = 0; i < M; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
    pq[from].push(to);
    pq[to].push(from);
  }

  cin >> S >> E;

  // S -> E까지 구하기
  SToE();

  // E -> S까지 구하기
  EToS();

  cout << ans;

  return 0; 
}