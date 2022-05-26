#include <bits/stdc++.h>

using namespace std;

int N, M;

int fun(int n, int m) {
  if(n == 1 && m == 1) {
    return 0;
  }

  if(n == 1) {
    return m - 1;
  }

  return fun(n - 1, m) + m;
}

int main() {
  cin >> N >> M;

  cout << fun(N, M);

  return 0;
}