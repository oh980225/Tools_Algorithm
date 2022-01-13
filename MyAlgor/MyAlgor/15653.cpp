#include <bits/stdc++.h>

using namespace std;

int N, M;
int matrix[11][11];
bool visited[11][11][11][11];
pair<int, int> red;
pair<int, int> blue;

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

struct INFO {
  int redY, redX, blueY, blueX, cnt;
};

void input() {
  cin >> N >> M;
  string str;
  for(int i = 0; i < N; i++) {
    cin >> str;
    int size = str.size();
    for(int j = 0; j < size; j++) {
      matrix[i][j] = str[j];
      if(matrix[i][j] == 'R')
        red = {i, j};

      if(matrix[i][j] == 'B')
        blue = {i, j};
    }
  }
}

void playGame() {
  visited[red.first][red.second][blue.first][blue.second] = true;
  queue<INFO> q;
  q.push({red.first, red.second, blue.first, blue.second, 0});

  while(!q.empty()) {
    auto curInfo = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int newRedY = curInfo.redY + dY[i];
      int newRedX = curInfo.redX + dX[i];
      int newBlueY = curInfo.blueY + dY[i];
      int newBlueX = curInfo.blueX + dX[i];
      bool redFlag = false;
      bool blueFlag = false;

      // red ball
      while(true) {
        if(matrix[newRedY][newRedX] == '#')
          break;

        if(matrix[newRedY][newRedX] == 'O') {
          redFlag = true;
          break;
        }

        newRedY += dY[i];
        newRedX += dX[i];
      }
      newRedY -= dY[i];
      newRedX -= dX[i];

      // blue ball
      while(true) {
        if(matrix[newBlueY][newBlueX] == '#')
          break;

        if(matrix[newBlueY][newBlueX] == 'O') {
          blueFlag = true;
          break;
        }

        newBlueY += dY[i];
        newBlueX += dX[i];
      }
      newBlueY -= dY[i];
      newBlueX -= dX[i];

      if(blueFlag)
        continue;
      
      if(redFlag) {
        cout << curInfo.cnt + 1;
        return;
      }

      if(newRedY == newBlueY && newRedX == newBlueX) {
        int redDistance = abs(newRedY - curInfo.redY) + abs(newRedX - curInfo.redX);
        int blueDistance = abs(newBlueY - curInfo.blueY) + abs(newBlueX - curInfo.blueX);

        if(redDistance > blueDistance) {
          newRedY -= dY[i];
          newRedX -= dX[i];
        }
        if(redDistance < blueDistance) {
          newBlueY -= dY[i];
          newBlueX -= dX[i];
        }
      }

      if(visited[newRedY][newRedX][newBlueY][newBlueX])
        continue;
      visited[newRedY][newRedX][newBlueY][newBlueX] = true;
      q.push({newRedY, newRedX, newBlueY, newBlueX, curInfo.cnt + 1});
    }
  }

  cout << -1;
  return;
}

int main() {
  input();

  playGame();

  return 0;
}