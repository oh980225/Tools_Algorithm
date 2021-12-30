#include <bits/stdc++.h>
 
using namespace std;

struct FISH {
  int y, x, dir;
  bool live;
};

int result;
int room[4][4];
FISH fishes[17];

int dY[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dX[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void input() {
  int number, dir;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> number >> dir;
      room[i][j] = number;
      fishes[number] = {i, j, dir, true};
    }
  }
}

void copyFishAndRoom(int originRoom[4][4], int targetRoom[4][4], FISH originFish[17], FISH targetFish[17]) {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      targetRoom[i][j] = originRoom[i][j];
    }
  }

  for(int i = 1; i <= 16; i++) {
    targetFish[i] = originFish[i];
  }
}

void swapFish(int idx, int target) {
  FISH temp = fishes[idx];
  fishes[idx].y = fishes[target].y;
  fishes[idx].x = fishes[target].x;
  fishes[target].y = temp.y;
  fishes[target].x = temp.x;
}

void moveFish() {
  for(int i = 1; i <= 16; i++) {
    if(!fishes[i].live) {
      continue;
    }
    int curDir = fishes[i].dir;
    for(int j = 0; j < 8; j++) {
      if(curDir == 9) {
        curDir = 1;
      }
      int y = fishes[i].y;
      int x = fishes[i].x;
      
      int newY = y + dY[curDir];
      int newX = x + dX[curDir];

      if(0 <= newY && newY < 4 && 0 <= newX && newX < 4) {
        if(!room[newY][newX]) {
          fishes[i].y = newY;
          fishes[i].x = newX;
          room[newY][newX] = i;
          room[y][x] = 0;
          fishes[i].dir = curDir;
          break;
        }
        else if(room[newY][newX] != -1) {
          swapFish(i, room[newY][newX]);
          swap(room[y][x], room[newY][newX]);
          fishes[i].dir = curDir;
          break;
        }
      }
      curDir++;
    }
  }
}

void dfs(int y, int x, int dir, int sum) {
  result = max(result, sum);
  int copyRoom[4][4];
  FISH copyFish[17];
  copyFishAndRoom(room, copyRoom, fishes, copyFish);
  moveFish();

  for(int i = 1; i <=3; i++) {
    int newY = y + dY[dir] * i;
    int newX = x + dX[dir] * i;
    
    if(0 <= newY && newY < 4 && 0 <= newX && newX < 4) {
      if(!room[newY][newX]) {
        continue;
      }

      int roomNum = room[newY][newX];
      int newDir = fishes[roomNum].dir;
      room[y][x] = 0;
      room[newY][newX] = -1;
      fishes[roomNum].live = false;
      dfs(newY, newX, newDir, sum + roomNum);
      room[y][x] = -1;
      room[newY][newX] = roomNum;
      fishes[roomNum].live = true;
      continue;
    }
    
    break;
  }
  copyFishAndRoom(copyRoom, room, copyFish, fishes);
}

void moveFishAndShark() {
  int initNum = room[0][0];
  int dir = fishes[initNum].dir;
  fishes[initNum].live = false;
  room[0][0] = -1;
  dfs(0, 0, dir, initNum);
}

int main() {
  input();

  moveFishAndShark();
  
  cout << result;

  return 0;  
}