#include <bits/stdc++.h>

using namespace std;

int N, K, S, X, Y;
int matrix[201][201];

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

struct VIRUS {
  int x, y, num, time;
};

bool operator < (VIRUS a, VIRUS b) {
  if(a.time == b.time) {
    return a.num > b.num;
  }

  return a.time > b.time;
}

int main() {
  priority_queue<VIRUS> pq;

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j]) {
        pq.push({i, j, matrix[i][j], 0});
      }
    }
  }
  cin >> S >> X >> Y;

  while(pq.size()) {
    auto cur = pq.top();
    pq.pop();

    if(cur.time == S) {
      break;
    }

    if(matrix[X - 1][Y - 1]) {
      cout << matrix[X - 1][Y - 1];
      return 0;
    }

    for(int i = 0; i < 4; i++) {
      int newY = dY[i] + cur.y;
      int newX = dX[i] + cur.x;
      if(0 <= newY && newY < N && 0 <= newX && newX < N && !matrix[newX][newY]) {
        matrix[newX][newY] = cur.num;
        pq.push({newX, newY, cur.num, cur.time + 1});
      }
    }
  }

  cout << matrix[X - 1][Y - 1];

  return 0;
}