#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> h;
stack<int> s;

int main() {
  cin >> N;
  int x, y;

  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    h.push_back(y);
  }

  int result = 0;
  for(int i = 0; i < N; i++) {
    int cur = h[i];

    while(!s.empty() && s.top() > cur) {
      // 높이가 0이면 건물 X
      if(s.top())
        result++;

      s.pop();
    }

    // 높이가 같은 것은 같은 고도의 건물 1개
    if(!s.empty() && s.top() == cur)
      continue;

    s.push(cur);
  }

  while(!s.empty()) {
    if(s.top())
      result++;
    s.pop();
  }

  cout << result;

  return 0;
}