#include <bits/stdc++.h>

using namespace std;

int N;
int C[505];
int matrix[505][505];

void input() {
  cin >> N;
  int r, c;
  int idx = 0;
  for(int i = 0; i < N; i++) {
    cin >> r >> c;
    if(i == 0) {
      C[idx++] = r;
    }
    C[idx++] = c;
  }
}

void output() {
  cout << matrix[1][N];
}

int findPartMin(int y, int x) {
  int result = INT_MAX;

  for(int i = y; i <= x - 1; i++) {
    result = min(result, matrix[y][i] + matrix[i + 1][x] + C[y - 1] * C[i] * C[x]);
  }

  return result;
}

void multiplyMatrix() {
  for(int d = 1; d <= N - 1; d++) {
    for(int i = 1; i <= N - d; i++) {
      matrix[i][i + d] = findPartMin(i, i + d);
    }
  }
}

int main() {
  input();

  multiplyMatrix();

  output();

  return 0;
}