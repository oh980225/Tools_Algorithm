#include <bits/stdc++.h>

using namespace std;

bool checkGrid[3][3][10];
bool checkRow[10][10];
bool checkCol[10][10];
int matrix[10][10];
bool flag = false;

void writeMatrix(int y, int x, int num) {
  matrix[y][x] = num;
  checkRow[y][num] = true;
  checkCol[x][num] = true;
  checkGrid[(y - 1) / 3][(x - 1) / 3][num] = true;
}

void eraseMatrix(int y, int x, int num) {
  matrix[y][x] = 0;
  checkRow[y][num] = false;
  checkCol[x][num] = false;
  checkGrid[(y - 1) / 3][(x - 1) / 3][num] = false;
}

void input() {
  int num;

  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cin >> num;
      writeMatrix(i, j, num);
    }
  }
}

void output() {
  cout << "------------------\n";
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

pair<int, int> nextBlank(int y, int x) {
  int newX = x + 1;
  int newY = y;

  if(9 < newX) {
    newX = 1;
    newY += 1;
  }

  return {newY, newX};
}

void playGame(int y, int x) {
  if(y == 10 && x == 1) {
    if(!flag) {
      output();
      flag = true;
    }
    return;
  }

  if(matrix[y][x]) {
    auto next = nextBlank(y, x);
    playGame(next.first, next.second);
    return;
  }

  for(int i = 1; i <= 9; i++) {
    if(!checkGrid[(y - 1) / 3][(x - 1) / 3][i] && !checkRow[y][i] && !checkCol[x][i]) {
      writeMatrix(y, x, i);
      auto next = nextBlank(y, x);
      playGame(next.first, next.second);
      eraseMatrix(y, x, i);
    }
  }
}

int main () {
  input();

  playGame(1, 1);

  return 0;
}