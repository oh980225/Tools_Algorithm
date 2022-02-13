#include <bits/stdc++.h>

using namespace std;

// 1초, 512MB -> 10^8
// 행의 수 N
// 열의 수 M 
// 1 <= N, M <= 25
// 1 <= N * M <= 25

int N, M;
int matrix[27][27];
int ans;

// 2X2 칸이 있는지 확인
bool checkSquare() {
  for(int i = 0; i < 24; i++) {
    for(int j = 0; j < 24; j++) {
      if(matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1] && matrix[i + 1][j + 1]) {
        return true;
      }
    }
  }

  return false;
}

// 백트래킹
void dfs(int y, int x) {  
  if(y == N + 1 && x == 1) {
    ans++;
    return;
  }

  if(x > M) {
    dfs(y + 1, 1);
    return;
  }

  if(!matrix[y - 1][x] || !matrix[y - 1][x - 1] || !matrix[y][x - 1]) {
    matrix[y][x] = 1;
    dfs(y, x + 1);
    matrix[y][x] = 0;
  }

  dfs(y, x + 1);
}

int main() {
  cin >> N >> M;

  dfs(1, 1);

  cout << ans;

  return 0;
}