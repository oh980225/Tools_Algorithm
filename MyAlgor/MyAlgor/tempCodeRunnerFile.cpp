#include <bits/stdc++.h>

using namespace std;

int N, M, H, result;

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};
int matrix[11][11];
int homeY = -1;
int homeX = -1;

void input() {
  cin >> N >> M >> H;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j] == 1) {
        homeY = i;
        homeX = j;
      }
    }
  }
}

void findMint(int y, int x, int health, int cnt) {
  if(!health) {
    if(matrix[y][x] == 1) 
      result = max(result, cnt);
    return;
  }

  if(matrix[y][x] == 1) {
    result = max(result, cnt);
    return;
  }

  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    if(0 <= newY && newY < N && 0 <= newX && newX < N) {
      if(matrix[newY][newX] == 2) {
        matrix[newY][newX] = 0;
        findMint(newY, newX, health + H - 1, cnt + 1);
        matrix[newY][newX] = 2;
        continue;
      }
      findMint(newY, newX, health - 1, cnt);
    }
  }
}

void output() {
  cout << result;
}

int main() {
  input();

  findMint(homeY, homeX, M, 0);

  output();

  return 0;
}