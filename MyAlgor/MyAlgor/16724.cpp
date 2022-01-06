#include <bits/stdc++.h>

using namespace std;

char matrix[1000][1000];
int check[1000][1000];
int curChecker;
int result;
int N, M;

void input() {
  cin >> N >> M;

  for(int i = 0; i < N; i++) 
    for(int j = 0; j < M; j++) 
      cin >> matrix[i][j];
}

void output() {
  cout << result;
}

pair<int, int> direction(int y, int x) {
  if(matrix[y][x] == 'D') {
    return {1, 0};
  }
  if(matrix[y][x] == 'U') {
    return {-1, 0};
  }
  if(matrix[y][x] == 'R') {
    return {0, 1};
  }
  if(matrix[y][x] == 'L') {
    return {0, -1};
  }
  return {0, 0};
}

void dfs(int y, int x) {
  if(check[y][x]) {
    if(check[y][x] != curChecker) 
      result--;
    return;
  }

  check[y][x] = curChecker;
  auto dir = direction(y, x);
  dfs(y + dir.first, x + dir.second);
}

void safeZone(int y, int x) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(!check[i][j]) {
        curChecker++;
        result++;
        dfs(i, j);
      }
    }
  }
}

int main() {
  input();

  safeZone(0, 0);

  output();

  return 0;
}