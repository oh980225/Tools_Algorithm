#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int matrix[1001][1001];
bool check[1001][1001][11][2];
int isMorning;

int dY[] = {0, 0, 0, -1, 1};
int dX[] = {0, 1, -1, 0, 0};

struct POS {
  int y, x, count, wall;
};

void input() {
  cin >> N >> M >> K;
  string inputStr;
  for(int i = 0; i < N; i++) {
    cin >> inputStr;
    int idx = 0;
    for(auto str : inputStr) {
      matrix[i][idx++] = str - '0';
    }
  }
}

int minDistance() {
  queue<POS> q;
  q.push({0, 0, 1, 0});
  check[0][0][0][1] = true;

  while(!q.empty()) {
    POS curPOS = q.front();
    isMorning = curPOS.count % 2;
    q.pop();

    if(curPOS.y == (N - 1) && curPOS.x == (M - 1)) {
      return curPOS.count;
    }

    for(int i = 0; i < 5; i++) {
      int newY = curPOS.y + dY[i];
      int newX = curPOS.x + dX[i];
      int newIsMorning = isMorning ? 0 : 1;
      
      if(0 <= newY && newY < N && 0 <= newX && newX < M && !check[newY][newX][curPOS.wall][newIsMorning]) {
        if(matrix[newY][newX] && (dY[i] != 0 || dX[i] != 0)) {
          if(curPOS.wall < K && !newIsMorning) {
            check[newY][newX][curPOS.wall][newIsMorning] = true;
            q.push({newY, newX, curPOS.count + 1, curPOS.wall + 1});
          }
          continue;
        }
        check[newY][newX][curPOS.wall][newIsMorning] = true;
        q.push({newY, newX, curPOS.count + 1, curPOS.wall});
      }
    }
  }

  return -1;
}

int main() {
  input();

  int result = minDistance();
  cout << result;

  return 0;
}