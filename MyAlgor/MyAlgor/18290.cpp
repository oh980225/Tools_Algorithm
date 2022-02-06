#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int matrix[11][11];
bool chk[11][11];
int ans = INT_MIN;

int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};

bool chkAdj(int y, int x) {
  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    if(0 <= newY && newY < N && 0 <= newX && newX < M) {
      if(chk[newY][newX])
        return false;
    }
  }
  return true;
} 

void dfs(int y, int x, int cnt, int value) {
  if(cnt == K) {
    ans = max(ans, value);
    return;
  }

  if(x + 1 >= M) {
    if(y + 1 >= N) 
      return;

    if(chkAdj(y + 1, 0)) {
      chk[y + 1][0] = true;
      dfs(y + 1, 0, cnt + 1, value + matrix[y + 1][0]);
    }
    chk[y + 1][0] = false;
    dfs(y + 1, 0, cnt, value);
    return;
  }

  if(chkAdj(y, x + 1)) {
    chk[y][x + 1] = true;
    dfs(y, x + 1, cnt + 1, value + matrix[y][x + 1]);
  }
  chk[y][x + 1] = false;
  dfs(y, x + 1, cnt, value);
}

int main() {
  cin >> N >> M >> K;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> matrix[i][j];
    }
  }

  chk[0][0] = true;
  dfs(0, 0, 1, matrix[0][0]);

  chk[0][0] = false;
  dfs(0, 0, 0, 0);

  cout << ans;

  return 0;
}