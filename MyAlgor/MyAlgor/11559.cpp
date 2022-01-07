#include <bits/stdc++.h>

using namespace std;

char matrix[12][6];
char temp[12][6];
int result;
bool flag;
char curColor;
int cnt;

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

void input() {
  string input;
  for(int i = 0; i < 12; i++) {
    cin >> input;
    for(int j = 0; j < input.size(); j++) {
      matrix[i][j] = input[j];
    }
  }
}

void output() {
  cout << result;
}

void downBlock() {
  for(int i = 0; i < 6; i++) {
    int init = 11;
    for(int j = 11; 0 <= j; j--) {
      if(matrix[j][i] != '.') {
        swap(matrix[init--][i], matrix[j][i]);
      }
    }
  }
}

void dfsBlock(int y, int x) {
  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];

    if(0 <= newY && newY < 12 && 0 <= newX && newX < 6 && temp[newY][newX] == curColor) {
      temp[newY][newX] = '.';
      cnt++;
      dfsBlock(newY, newX);
    }
  }
}

void boomBlock() {
  for(int i = 0; i < 12; i++) {
    for(int j = 0; j < 6; j++) {
      bool loopFlag = false;

      if(matrix[i][j] != '.') {
        memcpy(temp, matrix, sizeof(matrix));
        curColor = matrix[i][j];
        cnt = 1;
        temp[i][j] = '.';
        
        dfsBlock(i, j);

        if(4 <= cnt) {
          loopFlag = true;
        }

        if(!flag && 4 <= cnt) {
          flag = true;
          result++;
        }
      }

      if(loopFlag) {
        memcpy(matrix, temp, sizeof(temp));
      }
    }
  }
}

void playGame() {
  while(true) {
    boomBlock();

    if(!flag) {
      return;
    }

    downBlock();
    flag = false;
  }
}


int main() {
  input();

  playGame();

  output();

  return 0;
}