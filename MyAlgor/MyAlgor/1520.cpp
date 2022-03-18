#include <bits/stdc++.h>

using namespace std;

// M -> 행
// N -> 열
int M, N;
int matrix[501][501];
int visited[501][501];
int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

int dfs(int y, int x) {
  if(visited[y][x] != -1) {
    return visited[y][x];
  }

  visited[y][x] = 0;
  int curH = matrix[y][x];
  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    if(0 <= newY && newY < M && 0 <= newX && newX < N) {
      int nextH = matrix[newY][newX];
      if(curH > nextH) {
        visited[y][x] += dfs(newY, newX);
      }
    }
  }

  return visited[y][x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      cin >> matrix[i][j];
      visited[i][j] = -1;
    }
  }

  visited[M - 1][N - 1] = 1;
  dfs(0, 0);

  cout << visited[0][0];

  return 0;
}