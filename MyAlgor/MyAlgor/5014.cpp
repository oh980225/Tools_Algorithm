#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
bool chk[1000001];
int ans = -1;

int main() {
  cin >> F >> S >> G >> U >> D;

  queue<pair<int, int>> q;
  q.push({S, 0});
  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur.first == G) {
      ans = cur.second;
      break;
    }

    int upCase = cur.first + U;
    if(upCase <= F && !chk[upCase]) {
      chk[upCase] = true;
      q.push({upCase, cur.second + 1});
    }

    int downCase = cur.first - D;
    if(1 <= downCase && !chk[downCase]) {
      chk[downCase] = true;
      q.push({downCase, cur.second + 1});
    }
  }

  if(ans == -1) {
    cout << "use the stairs";
    return 0;
  }

  cout << ans;
  return 0;
}