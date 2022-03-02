#include <bits/stdc++.h>

using namespace std;

int N, M;
int matrix[301][301];
int memo[301][301];

int main() {
  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> matrix[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]) + matrix[i][j];
    }
  }

  cout << memo[N][M];

  return 0;
}