#include <bits/stdc++.h>

using namespace std;

int N, M, fuel;

int taxiY, taxiX;
int matrix[21][21]; 
bool check[21][21];

int dY[] = {0, 0, -1, 1};
int dX[] = {-1, 1, 0, 0};

struct CUS {
  int endY, endX;
};

CUS customer[405];

struct INFO {
  int y, x, dist, num;
};

struct TAXI {
  int y, x, dist, remain;
};

bool checkRange(int y, int x) {
  return 1 <= y && y <= N && 1 <= x && x <= N;
}

bool INFO_Compare(INFO a, INFO b) {
  if(a.dist <= b.dist) {
    if(a.dist == b.dist) {
      if(a.y <= b.y) {
        if(a.y == b.y) {
          if(a.x < b.x) {
            return true;
          }
          return false;
        }
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

int moveToCus(int y, int x) {
  memset(check, 0, sizeof(check));
  vector<INFO> info;
  queue<TAXI> q;
  q.push({y, x, 0, fuel});
  check[y][x] = true;

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur.remain == 0) {
      continue;
    }

    if(matrix[cur.y][cur.x] >= 1) {
      info.push_back({cur.y, cur.x, cur.dist, matrix[cur.y][cur.x]});
      continue;
    }

    for(int i = 0; i < 4; i++) {
      int newY = cur.y + dY[i];
      int newX = cur.x + dX[i];
      if(checkRange(newY, newX) && matrix[newY][newX] != -1 && !check[newY][newX]) {
        check[newY][newX] = true;
        q.push({newY, newX, cur.dist + 1, cur.remain - 1});
      }
    }
  }

  if(!info.size()) {
    return -1;
  }

  sort(info.begin(), info.end(), INFO_Compare);
  matrix[info[0].y][info[0].x] = 0;
  fuel -= info[0].dist;
  taxiY = info[0].y;
  taxiX = info[0].x;
  return info[0].num;  
}

bool goDestination(int y, int x, int cusNum) {
  memset(check, 0, sizeof(check));
  queue<TAXI> q;
  q.push({y, x, 0, fuel});
  check[y][x] = true;
  int destY = customer[cusNum].endY;
  int destX = customer[cusNum].endX;

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur.y == destY && cur.x == destX) {
      fuel += cur.dist;
      taxiY = destY;
      taxiX = destX;
      return true;
    }

    if(cur.remain == 0) {
      continue;
    }

    for(int i = 0; i < 4; i++) {
      int newY = cur.y + dY[i];
      int newX = cur.x + dX[i];
      if(checkRange(newY, newX) && matrix[newY][newX] != -1 && !check[newY][newX]) {
        check[newY][newX] = true;
        q.push({newY, newX, cur.dist + 1, cur.remain - 1});
      }
    }
  }

  return false; 
}

int main() {
  cin >> N >> M >> fuel;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j]) {
        matrix[i][j] = -1;
      }
    }
  }

  cin >> taxiY >> taxiX;

  int startY, startX, endY, endX;
  for(int i = 1; i <= M; i++) {
    cin >> startY >> startX >> endY >> endX;
    customer[i] = {endY, endX};
    matrix[startY][startX] = i;
  }
  
  for(int i = 0; i < M; i++) {
    int cusNum = moveToCus(taxiY, taxiX);

    if(cusNum == -1) {
      cout << -1;
      return 0;
    }

    bool go = goDestination(taxiY, taxiX, cusNum);

    if(!go) {
      cout << -1;
      return 0;
    }
  }
  cout << fuel;

  return 0;
}