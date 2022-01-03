#include <bits/stdc++.h>

using namespace std;

int matrix[10][10];
bool checkRow[10][10];
bool checkCol[10][10];
bool checkGrid[3][3][10];
bool checkDomino[10][10];


int dY[] = {0, 0, 1, -1};
int dX[] = {1, -1, 0, 0};
int idx = 1;
int N;
bool flag = false;

int getIdx(char input) {
  if(input == 'A' || input == '1') {
    return 1;
  }
  if(input == 'B' || input == '2') {
    return 2;
  }
  if(input == 'C' || input == '3') {
    return 3;
  }
  if(input == 'D' || input == '4') {
    return 4;
  }
  if(input == 'E' || input == '5') {
    return 5;
  }
  if(input == 'F' || input == '6') {
    return 6;
  }
  if(input == 'G' || input == '7') {
    return 7;
  }
  if(input == 'H' || input == '8') {
    return 8;
  }
  if(input == 'I' || input == '9') {
    return 9;
  }
  return -1;
}

void writeNumber(int y, int x, int num) {
  checkRow[y][num] = true;
  checkCol[x][num] = true;
  checkGrid[(y - 1) / 3][(x - 1) / 3][num] = true;
  matrix[y][x] = num;
}

void eraseNumber(int y, int x, int num) {
  checkRow[y][num] = false;
  checkCol[x][num] = false;
  checkGrid[(y - 1) / 3][(x - 1) / 3][num] = false;
  matrix[y][x] = 0;
}

void input() {  
  int U, V;
  string LU, LV;
  for(int i = 0; i < N; i++) {
    cin >> U >> LU >> V >> LV;

    checkDomino[U][V] = true;
    checkDomino[V][U] = true;

    int firstY = getIdx(LU[0]);
    int firstX = getIdx(LU[1]);
    int secondY = getIdx(LV[0]);
    int secondX = getIdx(LV[1]);
    
    writeNumber(firstY, firstX, U);
    writeNumber(secondY, secondX, V);
  }

  string str;
  for(int i = 1; i <= 9; i++) {
    cin >> str;

    int y = getIdx(str[0]);
    int x = getIdx(str[1]);

    writeNumber(y, x, i);
  }
}

void output() {
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void playGame(int y, int x) {
  if(y == 9 && x == 9 && !flag) {
    flag = true;
    cout << "Puzzle " << idx << endl;
    output();
    return;
  }

  if(matrix[y][x]) {
    int nextX = x + 1;
    int nextY = y;
    if(9 < nextX) {
      nextX = 1;
      nextY += 1;
    }
    
    playGame(nextY, nextX);
    return;
  }

  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    for(int k = 1; k <= 9; k++) {
      if(!checkRow[y][k] && !checkCol[x][k] && !checkGrid[(y - 1) / 3][(x - 1) / 3][k]) {
        writeNumber(y, x, k);

        if(0 <= newY && newY <= 9 && 0 <= newX && newX <= 9 && !matrix[newY][newX]) {
          for(int j = 1; j <= 9; j++) {
            if(!checkRow[newY][j] && !checkCol[newX][j] && !checkGrid[(newY - 1) / 3][(newX - 1) / 3][j] && !checkDomino[k][j]) {
              writeNumber(newY, newX, j);
              checkDomino[k][j] = true;
              checkDomino[j][k] = true;

              int nextX = x + 1;
              int nextY = y;
              if(9 < nextX) {
                nextX = 1;
                nextY += 1;
              }
    
              playGame(nextY, nextX);

              checkDomino[k][j] = false;
              checkDomino[j][k] = false;
              eraseNumber(newY, newX, j);
            }
          }
        }
        eraseNumber(y, x, k);
      }
    }
  }
  return;
}

void init() {
  memset(matrix, 0, sizeof(matrix));
  memset(checkRow, 0, sizeof(checkRow));
  memset(checkCol, 0, sizeof(checkCol));
  memset(checkGrid, 0, sizeof(checkGrid));
  memset(checkDomino, 0, sizeof(checkDomino));
}

int main() {
  while(true) {
    cin >> N;

    if(N == 0)
      break;
    
    input();
    
    playGame(1, 1);
    flag = false;
    idx++;
    init();
  }
  return 0;
}