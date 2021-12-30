#include <bits/stdc++.h>

using namespace std;

int N, sharkX, sharkY, eatCnt, minDist, minX, minY, answer, sharkSize = 2;
int room[21][21];
int check[21][21];

int dY[] = {0, 0, 1, -1};
int dX[] = {1, -1, 0, 0};

void input() {
  cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> room[i][j];

      if(room[i][j] == 9) {
        sharkY = i;
        sharkX = j;
        room[i][j] = 0;
      }
    }
  }
}

void init() {
  minX = 21;
  minY = 21;
  minDist = 401;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      check[i][j] = -1;
    }
  }
}

void findFish() {
  queue<pair<int, int>> q;
  q.push({sharkY, sharkX});
  check[sharkY][sharkX] = 0;

  while(!q.empty()) {
    auto cur = q.front();
    int y = cur.first;
    int x = cur.second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int newY = y + dY[i];
      int newX = x + dX[i];

      if(0 <= newY && newY < N && 0 <= newX && newX < N && check[newY][newX] == -1 && room[newY][newX] <= sharkSize) {
        check[newY][newX] = check[y][x] + 1;
        
        if(room[newY][newX] < sharkSize && room[newY][newX]) {
          if(check[newY][newX] < minDist) {
          minX = newX;
          minY = newY;
          minDist = check[newY][newX];
          } else if(check[newY][newX] == minDist) {
            if(newY == minY) {
              if(newX < minX) {
                minX = newX;
              }
            } else if(newY < minY) {
              minY = newY;
              minX = newX;
            }
          }
        }
        q.push({newY, newX});
      }
    }
  }
}

void moveAndEat() {
  while(true) {
    init();

    findFish();

    if(minX != 21 || minY != 21) {
      answer += check[minY][minX];
      eatCnt++;

      if(eatCnt == sharkSize) {
        eatCnt = 0;
        sharkSize++;
      }

      room[minY][minX] = 0;
      sharkY = minY;
      sharkX = minX;
      continue;
    }

    break;
  }
}

int main() {
  input();

  moveAndEat();

  cout << answer;

  return 0;
}