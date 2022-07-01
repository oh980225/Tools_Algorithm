#include <bits/stdc++.h>

using namespace std;

int N;
bool chk[101];
vector<long long> v;
long long ans[101];

void dfs(int x) {
  if(x == N) {
    for(int i = 0; i < N; i++) {
      cout << ans[i] << ' ';
    }
    exit(0);
  }

  for(int i = 0; i < N; i++) {
    if(chk[i]) 
      continue;

    if(ans[x - 1] == 3 * v[i]) {
      chk[i] = true;
      ans[x] = v[i];
      dfs(x + 1);
      chk[i] = false;
    }

    if(ans[x - 1] * 2 == v[i]) {
      chk[i] = true;
      ans[x] = v[i];
      dfs(x + 1);
      chk[i] = false;
    }
  }
}

int main() {
  cin >> N;

  long long num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  for(int i = 0; i < N; i++) {
    chk[i] = true;
    ans[0] = v[i];
    dfs(1);
    chk[i] = false;
  }

  return 0;
}