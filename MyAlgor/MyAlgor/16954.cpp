#include <bits/stdc++.h>

using namespace std;

struct PERSON {
  int y, x, time;
};

char board[9][9];
int dY[] = {0, 0, -1, -1, -1, 0, 1, 1 ,1};
int dX[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void input() {
  string input;
  for(int i = 0; i < 8; i++) {
    cin >> input;
    for(int j = 0; j < 8; j++) {
      board[i][j] = input[j];
    }
  }
}

void moveDownWall() {
  for(int i = 7; 0 < i; i--) {
    int upI = i - 1;
    for(int j = 0; j < 8; j++) {
      board[i][j] = board[upI][j];
    }
  }
  for(int i = 0; i < 8; i++) {
    board[0][i] = '.';
  }
}

int clearGame() {
  queue<PERSON> q;
  q.push({7, 0, 0});
  int preTime = 0;

  while(!q.empty()) {
    int y = q.front().y;
    int x = q.front().x;
    int time = q.front().time;
    q.pop();

    if(y == 0 && x == 7) 
      return 1;

    if(preTime < time) {
      preTime = time;
      moveDownWall();
    }

    if(board[y][x] == '#') 
      continue;

    for(int i = 0; i < 9; i++) {
      int newY = y + dY[i];
      int newX = x + dX[i];

      if(0 <= newY && newY < 8 && 0 <= newX && newX < 8 && board[newY][newX] == '.')
        q.push({newY, newX, time + 1});
    }
  }
  return 0;
}

int main() {
  input();

  int result = clearGame();

  cout << result;

  return 0;
}