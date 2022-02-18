#include <bits/stdc++.h>

using namespace std;

int N, M;
char matrix[11][11];

// 상, 하, 좌, 우
int dY[] = {-1, 1, 0, 0};
int dX[] = {0, 0, -1, 1};

pair<int, int> R, B;
int ans;

// 1. 상하좌우로 이동하는 것은 정해진 방향으로 #이나 다른 구슬(R,B)가 나올때 까지!
// 2. R, B의 위치를 기억하며 더 기울이는 방향 쪽에 가까운 것을 먼저 이동!
// 3. 만약 O가 나오면 구슬 없애고 해당하는 구슬 flag를 true
// 4. 이동할 때마다 R,B의 flag를 check -> 둘 중 하나가 true면 일단 재귀 X -> R만 true이면 답은 1! 모두 종료
// 5. 기저 사례는 기울인 횟수가 10번 초과 + ans가 1로 이미 해당 경우를 찾은 경우

bool firstR(int i, int RY, int RX, int BY, int BX) {
  if(i == 0) {
    return RY < BY;
  }

  if(i == 1) {
    return RY > BY;
  }

  if(i == 2) {
    return RX < BX;
  }

  if(i == 3) {
    return RX > BX;
  }

  return false;
}

void dfs(int RY, int RX, int BY, int BX, int cnt) {
  // 이미 10번이상 기울인 경우
  if(cnt >= 10) {
    return;
  }

  // 이미 답을 찾은 경우
  if(ans) {
    return;
  } 

  for(int i = 0; i < 4; i++) {
    bool Rflag = false;
    bool Bflag = false;
    int tempRY = RY;
    int tempRX = RX;
    int tempBY = BY;
    int tempBX = BX;

    // R이 먼저인 경우
    if(firstR(i, RY, RX, BY, BX)) {
      // R 이동
      while(true) {
        tempRY += dY[i];
        tempRX += dX[i];

        if(matrix[tempRY][tempRX] == '#' || (tempRY == tempBY && tempRX == tempBX)) {
            tempRY -= dY[i];
            tempRX -= dX[i];
            break;
          }

          if(matrix[tempRY][tempRX] == 'O') {
            Rflag = true;
            break;
          }
      }

      // B 이동
      while(true) {
        tempBY += dY[i];
        tempBX += dX[i];

        if(matrix[tempBY][tempBX] == '#' || (tempRY == tempBY && tempRX == tempBX && !Rflag)) {
            tempBY -= dY[i];
            tempBX -= dX[i];
            break;
          }

          if(matrix[tempBY][tempBX] == 'O') {
            Bflag = true;
            break;
          }
      }
    }

    // B 먼저 이동
    else {
      // B 이동
      while(true) {
        tempBY += dY[i];
        tempBX += dX[i];

        if(matrix[tempBY][tempBX] == '#' || (tempRY == tempBY && tempRX == tempBX)) {
            tempBY -= dY[i];
            tempBX -= dX[i];
            break;
          }

        if(matrix[tempBY][tempBX] == 'O') {
          Bflag = true;
          break;
        }
      }

      // R 이동
      while(true) {
        tempRY += dY[i];
        tempRX += dX[i];

        if(matrix[tempRY][tempRX] == '#' || (tempRY == tempBY && tempRX == tempBX && !Bflag)) {
            tempRY -= dY[i];
            tempRX -= dX[i];
            break;
          }

        if(matrix[tempRY][tempRX] == 'O') {
          Rflag = true;
          break;
        }
      }
    }
    
    // R만 빠졌다면 ans = 1
    if(Rflag && !Bflag) {
      ans = 1;
      return;
    }

    if(!Rflag && !Bflag) {
      dfs(tempRY, tempRX, tempBY, tempBX, cnt + 1);
    }
  }
}

int main() {
  // 입력
  cin >> N >> M;
  string input;

  for(int i = 0; i < N; i++) {
    cin >> input;
    for(int j = 0; j < input.size(); j++) {
      if(input[j] == 'R') {
        R = {i, j};
        matrix[i][j] = '.';
        continue;
      }
      if(input[j] == 'B') {
        B = {i, j};
        matrix[i][j] = '.';
        continue;
      }

      matrix[i][j] = input[j];
    }
  }
  
  dfs(R.first, R.second, B.first, B.second, 0);

  cout << ans;

  return 0;
}