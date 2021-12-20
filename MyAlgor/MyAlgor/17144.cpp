#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int r, c, t;
int matrix[55][55];
int tempMatrix[55][55];
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};
vector<pair<int, int>> machine;

struct DUST {
  int y, x, amount;
};

void MoveDust(queue<DUST> q) {
  while(!q.empty()) {
    DUST dust = q.front();
    q.pop();
    int partOfDust = dust.amount / 5;
    int count = 0;

    for(int i = 0; i < 4; i++) {
      int newY = dust.y + dY[i];
      int newX = dust.x + dX[i];

      if(0 <= newX && newX < c && 0 <= newY && newY < r) {
        if(matrix[newY][newX] != -1) {
          count++;
          matrix[newY][newX] += partOfDust;
        }
      }
    }
    matrix[dust.y][dust.x] -= partOfDust * count;
  }
}

void diffuse() {
  queue<DUST> q;

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(matrix[i][j] > 4) {
        q.push({i, j, matrix[i][j]});
      }
    }
  }
  
  MoveDust(q);
}

void topOfTheMachine() {
  pair<int, int> direction[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
  int idx = 0;
  int curY = machine[0].first;
  int curX = machine[0].second + 1;
  matrix[curY][curX] = 0;

  while(true) {
    int newY = curY + direction[idx].first;
    int newX = curX + direction[idx].second;
    if(0 > newY || newY >= r || 0 > newX || newX >= c) {
      idx++;
      continue;
    }
    if(matrix[newY][newX] == -1) {
      break;
    }
    matrix[newY][newX] = tempMatrix[curY][curX];
    curY = newY;
    curX = newX;
  }
}

void downOfTheMachine() {
  pair<int, int> direction[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int idx = 0;
  int curY = machine[1].first;
  int curX = machine[1].second + 1;
  matrix[curY][curX] = 0;

  while(true) {
    int newY = curY + direction[idx].first;
    int newX = curX + direction[idx].second;
    if(0 > newY || newY >= r || 0 > newX || newX >= c) {
      idx++;
      continue;
    }
    if(matrix[newY][newX] == -1) {
      break;
    }
    matrix[newY][newX] = tempMatrix[curY][curX];
    curY = newY;
    curX = newX;
  }
}

void workMachine() {
  topOfTheMachine();
  downOfTheMachine();
}

void spreadDust(int time) {
  while(time--) {
    diffuse();
    memcpy(tempMatrix, matrix, sizeof(matrix));
    workMachine();
  }
}

int sumDust() {
  int total = 0;

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      total += matrix[i][j];
    }
  }

  return total + 2;
}

void input() {
  cin >> r >> c >> t;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j] == -1) {
        machine.push_back({i, j});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  spreadDust(t);
  int result = sumDust();

  cout << result;
  return 0;
}