#include <bits/stdc++.h>

using namespace std;

int N, M;
int memo[45];

int main() {
  memo[0] = 1;
  memo[1] = 1;
  memo[2] = 2;

  for(int i = 3; i <= 40; i++) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  cin >> N >> M;

  int pre = 0;
  int num;
  int ans = 1;

  while(M--) {
    cin >> num;
    int diff = num - pre - 1;
    ans *= memo[diff];
    pre = num;
  }

  ans *= memo[N - pre];

  cout << ans;

  return 0;
}