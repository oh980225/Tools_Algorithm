#include <bits/stdc++.h>

using namespace std;

// 1: 상
// 2: 하
// 3: 좌
// 4: 우

int dY[] = {0, -1, 1, 0, 0};
int dX[] = {0, 0 ,0, -1, 1};

int N, M, k;
int matrix[21][21];
pair<int, int> curSharkPos[405];
pair<int, int> history[21][21];
int curSharkDir[405];
int priorityDirPerShark[405][5][5];

void input() {
  cin >> N >> M >> k;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j]) { 
        history[i][j] = {matrix[i][j], k};
        curSharkPos[matrix[i][j]] = {i, j};
      }
    }
  }

  for(int i = 1; i <= M; i++) 
    cin >> curSharkDir[i];

  for(int i = 1; i <= M; i++) 
    for(int j = 1; j <= 4; j++) 
      for(int k = 1; k <= 4; k++) 
        cin >> priorityDirPerShark[i][j][k];
}

bool checkOneShark() {
  for(int i = 2; i <= M; i++) {
    if(curSharkPos[i].first != 0) 
      return false;
  }
  return true;
}

int main() {
  input();

  int sec = 0;
  while(sec <= 1000) {
    // 상어가 1번만 있는지!
    if(checkOneShark()) {
      cout << sec;
      return 0;
    }

    sec++;
    // 상어들 전부 이동
    // 이 방향으로 갈 수 있는지 체크
    // 방향 우선 순위를 보면서 냄새 없는 거 먼저 체크
    // 냄새 없는게 없으면 다시 방향 우선순위로 보면서 자신의 냄새가 있는 곳으로!
    // 이동 시 자기보다 낮은 번호 상어 있으면 현 상어 없애기
    for(int i = 1; i <= M; i++) {
      auto pos = curSharkPos[i];
      if(!pos.first) 
        continue;
      int curDir = curSharkDir[i];
      bool flag = false;
      for(int k = 1; k <= 4; k++) {
        int newDir = priorityDirPerShark[i][curDir][k];
        int newY = pos.first + dY[newDir];
        int newX = pos.second + dX[newDir];

        if(!(1 <= newY && newY <= N && 1 <= newX && newX <= N)) 
          continue;
        if(history[newY][newX].second <= 0) {
          if(!matrix[newY][newX]) {
            matrix[newY][newX] = i;
            matrix[pos.first][pos.second] = 0;
            curSharkPos[i] = {newY, newX};
            curSharkDir[i] = newDir;
            flag =true;
            break;
          }
          if(matrix[pos.first][pos.second] < matrix[newY][newX]) {
            curSharkPos[matrix[newY][newX]] = {0, 0};
            matrix[newY][newX] = i;
            matrix[pos.first][pos.second] = 0;
            curSharkPos[i] = {newY, newX};
            curSharkDir[i] = newDir;
            flag =true;
            break;
          }
          curSharkPos[i] = {0, 0};
          matrix[pos.first][pos.second] = 0;
          flag =true;
          break;
        }
      }

      if(flag) 
        continue;

      for(int k = 1; k <= 4; k++) {
        int newDir = priorityDirPerShark[i][curDir][k];
        int newY = pos.first + dY[newDir];
        int newX = pos.second + dX[newDir];
        if(!(1 <= newY && newY <= N && 1 <= newX && newX <= N)) 
          continue;
        if(history[newY][newX].first == i) {
          matrix[newY][newX] = matrix[pos.first][pos.second];
          matrix[pos.first][pos.second] = 0;
          curSharkPos[i] = {newY, newX};
          curSharkDir[i] = newDir;
          break;
        }
      }
    }
    // 이동 후 모든 맵 보면서 상어들이 있으면 냄새 생성(k)
    // 상어는 없는데 냄새는 있으면 냄새--
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(matrix[i][j]) { 
          history[i][j] = {matrix[i][j], k};
          continue;
        }
        if(history[i][j].second > 0) {
          history[i][j].second--;
        }
      }
    }
  }

  cout << -1;

  return 0;
}