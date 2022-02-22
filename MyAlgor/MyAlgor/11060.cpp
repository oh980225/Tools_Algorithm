#include <bits/stdc++.h>

using namespace std;

// i번째 칸 -> Ai => Ai이하만큼 오른쪽으로 떨어진 칸으로 점프
// 최소 몇번 점프해서 오른쪽 끝으로 갈 수 있는가! -> 불가할 경우 -1
// 1초 -> 10^8, 256MB
// 1 <= N <= 10^3
// 0 <= Ai <= 100

int N;
int ans = -1;
bool chk[1001];
vector<int> v;

int main() {
  cin >> N;

  int jump;
  for(int i = 0; i < N; i++) {
    cin >> jump;
    v.push_back(jump);
  }

  // bfs
  // first -> 현재 돌
  // second -> 현재까지 점프한 횟수
  queue<pair<int, int>> q;
  chk[0] = true;
  q.push({0, 0});

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur.first == N - 1) {
      ans = cur.second;
      break;
    }

    for(int i = 0; i <= v[cur.first]; i++) {
      if(cur.first + i > N - 1) {
        continue;
      }

      if(!chk[cur.first + i]) {
        chk[cur.first + i] = true;
        q.push({cur.first + i, cur.second + 1});
      }
    }
  }

  cout << ans;

  return 0;
}