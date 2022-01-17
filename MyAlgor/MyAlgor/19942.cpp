#include <bits/stdc++.h>

using namespace std;

int N, mp, mf, ms, mv;
int result = INT_MAX;
int ans[20];
int temp[20];
struct FOOD {
  int p, f, s, v, c;
};
FOOD foods[20];
bool chk[20];
int ansSize;

void input() {
  cin >> N;
  cin >> mp >> mf >> ms >> mv;

  int p, f, s, v, c;
  for(int i = 1; i <= N; i++) {
    cin >> p >> f >> s >> v >> c;
    foods[i] = {p, f, s, v, c};
  }
}

bool checkMinValue(int size) {
  int p = 0;
  int f = 0;
  int s = 0;
  int v = 0;
  int c = 0;
  for(int i = 1; i <= size; i++) {
    p += foods[temp[i]].p;
    f += foods[temp[i]].f;
    s += foods[temp[i]].s;
    v += foods[temp[i]].v;
    c += foods[temp[i]].c;
  }

  if(mp <= p && mf <= f && ms <= s && mv <= v && c < result) {
    result = c;
    memcpy(ans, temp, sizeof(temp));
    ansSize = size;
    return true;
  }

  return false;
}

void dfs(int num, int order) {
  if(checkMinValue(order - 1)) {
    return;  
  }

  for(int i = num; i <= N; i++) {
    if(!chk[i]) {
      chk[i] = true;
      temp[order] = i;
      dfs(i, order + 1);
      chk[i] = false;
    }
  }
}

int main() {
  input();

  for(int i = 1; i <= N; i++) {
    dfs(i, 1);
  }

  if(!ans[1]) {
    cout << -1 << '\n';
    cout << '\n';
    return 0;
  }

  cout << result << '\n';
  for(int i = 1; i <= ansSize; i++) {
    if(!ans[i]) 
      break;
    cout << ans[i] << " ";
  }

  return 0;
}