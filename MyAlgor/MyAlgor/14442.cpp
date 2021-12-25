#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int matrix[1001][1001];
bool check[1001][1001][11];

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

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
  check[0][0][0] = true;

  while(!q.empty()) {
    POS curPOS = q.front();
    q.pop();

    if(curPOS.y == (N - 1) && curPOS.x == (M - 1)) {
      return curPOS.count;
    }
    
    for(int i = 0; i < 4; i++) {
      int newY = curPOS.y + dY[i];
      int newX = curPOS.x + dX[i];
      if(0 <= newY && newY < N && 0 <= newX && newX < M && !check[newY][newX][curPOS.wall]) {
        if(matrix[newY][newX]) {
          if(curPOS.wall < K) {
            check[newY][newX][curPOS.wall + 1] = true;
            q.push({newY, newX, curPOS.count + 1, curPOS.wall + 1});
            continue;
          }
          continue;
        }
        check[newY][newX][curPOS.wall] = true;
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