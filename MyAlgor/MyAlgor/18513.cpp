#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll result = 0;
set<int> s;

int main() {
  cin >> N >> K;

  queue<pair<int, int>> q;
  int num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    s.insert(num);
    q.push({num, 0});
  }

  while(true) {
    auto cur = q.front();
    q.pop();

    int pre = cur.first - 1;

    if(s.count(pre) < 1) {
      result += cur.second + 1;
      s.insert(pre);
      q.push({pre, cur.second + 1});
      K--;
      if(!K)
        break;
    }

    int next = cur.first + 1;

    if(s.count(next) < 1) {
      result += cur.second + 1;
      s.insert(next);
      q.push({next, cur.second + 1});
      K--;
      if(!K)
        break;
    }
  }

  cout << result;
  return 0;
}