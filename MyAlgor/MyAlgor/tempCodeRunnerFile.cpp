#include <bits/stdc++.h>

using namespace std;

int N, M, init;

int matrix[21][21];
bool chk[21][21];
int taxiY;
int taxiX;

int dY[] = {-1, 0, 0, 1};
int dX[] = {0, -1, 1, 0};

struct PERSON {
  int endY, endX;
};
vector<PERSON> v;

int main() {
  cin >> N >> M >> init;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
    }
  }

  cin >> taxiY >> taxiX;

  v.resize(M + 3);
  int startY, startX, endY, endX;
  for(int i = 2; i < M + 2; i++) {
    cin >> startY >> startX >> endY >> endX;
    v[i] = {endY, endX};
    matrix[startY][startX] = i;
  }

  for(int k = 0; k < M; k++) {
    bool flag = false;
    int personNum = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{taxiY, taxiX}, 0});
    chk[taxiY][taxiX] = true;

    while(q.size()) {
      auto cur = q.front();
      q.pop();

      if(matrix[cur.first.first][cur.first.second] > 1) {
        personNum = matrix[cur.first.first][cur.first.second];
        matrix[cur.first.first][cur.first.second] = 0;
        init -= cur.second;
        startY = cur.first.first;
        startX = cur.first.second;
        flag = true;
        break;
      }

      for(int i = 0; i < 4; i++) {
        int newY = cur.first.first + dY[i];
        int newX = cur.first.second + dX[i];
        if(1 <= newY && newY <= N && 1 <= newX && newX <= N && matrix[newY][newX] != 1 && !chk[newY][newX]) {
          chk[newY][newX] = true;
          q.push({{newY, newX}, cur.second + 1});
        }
      }
    }

    if(!flag) {
      cout << -1;
      return 0;
    }

    memset(chk, 0, sizeof(chk));

    // 승객 태우러 가다가 연료 다 씀
    if(init <= 0) {
      cout << -1;
      return 0;
    }

    // 승객 도착 지점까지 최단 거리 구하기
    int usedFuel = 0;
    endY = v[personNum].endY;
    endX = v[personNum].endX;

    queue<pair<pair<int, int>, int>> driveQ;
    driveQ.push({{startY, startX}, 0});
    chk[startY][startX] = true;
    flag = false;
    while(driveQ.size()) {
      auto cur = driveQ.front();
      driveQ.pop();
      
      // 도착
      if(cur.first.first == endY && cur.first.second == endX) {
        usedFuel = cur.second;
        init -= usedFuel;
        flag = true;
        break;
      }

      for(int i = 0; i < 4; i++) {
        int newY = cur.first.first + dY[i];
        int newX = cur.first.second + dX[i];
        if(1 <= newY && newY <= N && 1 <= newX && newX <= N && matrix[newY][newX] != 1 && !chk[newY][newX]) {
          chk[newY][newX] = true;
          driveQ.push({{newY, newX}, cur.second + 1});
        }
      }
    }

    if(!flag) {
      cout << -1;
      return 0;
    }

    // 불가하면 return
    if(init < 0) {
      cout << -1;
      return 0;
    }

    // 가능하면 거기로 가고 + 연료 충전
    init += (usedFuel * 2);
    taxiY = endY;
    taxiX = endX;

    memset(chk, 0, sizeof(chk));
  }

  cout << init;

  return 0;
}