#include <bits/stdc++.h>

using namespace std;

int N;
bool chk[1001];
int roma[] = {1, 5, 10, 50};
int ans;

void dfs(int cnt, int num, int total) {
  if(cnt == N) {
    if(!chk[total]) {
      chk[total] = true;
      ans++;
    }

    return;
  }

  for(int i = num; i < 4; i++) {
    dfs(cnt + 1, i, total + roma[i]);
  }
}

int main() {
  cin >> N;

  dfs(0, 0, 0);

  cout << ans;

  return 0;
}