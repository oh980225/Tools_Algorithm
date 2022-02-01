#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e8;
int N, K;
bool chk[2 * MAX + 1];
ll result = 0;

int main() {
  cin >> N >> K;

  queue<pair<int, int>> q;
  int num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    num += MAX;
    chk[num] = true;
    q.push({num, 0});
  }

  while(true) {
    auto cur = q.front();
    q.pop();

    int pre = cur.first - 1;

    if(0 <= pre && pre <= 2 * MAX) {
      if(!chk[pre]) {
        result += cur.second + 1;
        chk[pre] = true;
        q.push({pre, cur.second + 1});
        K--;
        if(!K)
          break;
      }
    }

    int next = cur.first + 1;

    if(0 <= next && next <= 2 * MAX) {
      if(!chk[next]) {
        result += cur.second + 1;
        chk[next] = true;
        q.push({next, cur.second + 1});
        K--;
        if(!K)
          break;
      }
    }
  }

  cout << result;
  return 0;
}