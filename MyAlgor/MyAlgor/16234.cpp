#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

int n, l, r;
int countries[50][50];
bool check[50][50];
int days;

int moveY[4] = {0, 0, -1, 1};
int moveX[4] = {-1, 1, 0, 0};

void movePeople() {
  bool isMove;
  while(true) {
    isMove = false;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(!check[i][j]) {
          queue<pair<int, int>> q;
          queue<pair<int, int>> united;
          int total = 0;
          int count = 0;

          q.push({i, j});
          united.push({i, j});

          while(!q.empty()) {
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            check[curY][curX] = true;
            total += countries[curY][curX];
            count++;

            for(int k = 0; k < 4; k++) {
              int newY = curY + moveY[k];
              int newX = curX + moveX[k];
              if(0 <= newY && newY < n & 0 <= newX && newX < n && !check[newY][newX]) {
                int diff = abs(countries[curY][curX] - countries[newY][newX]);
                if(l <= diff && diff <= r) {
                  q.push({newY, newX});
                  united.push({newY, newX});
                  check[newY][newX] = true;
                  isMove = true;
                }
              }
            }
          }

          int average = total / count;

          while(!united.empty()) {
            int curY = united.front().first;
            int curX = united.front().second;
            countries[curY][curX] = average;
            united.pop();
          }
        }
      }
    }

    if(!isMove) {
      break;
    }
    
    days++;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        check[i][j] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l >> r;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> countries[i][j];
    }
  }

  movePeople();

  cout << days;

  return 0;
}