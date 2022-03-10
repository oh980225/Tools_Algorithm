#include <bits/stdc++.h>

using namespace std;

int N, M;
int K;
int circleX, circleY;

int matrix[20][20];
int memo[20][20];

void findCircle() {
  int idx = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(idx == K) {
        circleY = i;
        circleX = j;
        return;
      }
      idx++;
    }
  }
}

int main() {
  cin >> N >> M >> K;
  
  memo[1][1] = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(i == 1 && j == 1) {
        continue;
      }
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
    }
  }

  if(K) {
    findCircle();
    long long result = memo[circleY][circleX] * memo[N - circleY + 1][M - circleX + 1];
    cout << result;
    return 0;
  }

  cout << memo[N][M];

  return 0;
}