#include <bits/stdc++.h>

using namespace std;

int cnt;
int curSpace;
int maxSpace;
vector<vector<int>> space;
int maxY, maxX;

int dY[] = {0, 0, 1, -1};
int dX[] = {1, -1, 0, 0};

void dfs(int y, int x, int num) {
  space[y][x] = 0;
  curSpace++;

  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    if(0 <= newY && newY < maxY && 0 <= newX && newX < maxX) {
      if(space[newY][newX] == num) {
        dfs(newY, newX, num);
      }
    }
  }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
  cnt = 0;
  curSpace = 0;
  maxSpace = 0;
  space = picture;
  maxY = m;
  maxX = n;

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(space[i][j]) {
        cnt++;
        curSpace = 0;
        dfs(i, j, space[i][j]);
        maxSpace = max(maxSpace, curSpace);
      }
    }
  }

  return {cnt, maxSpace};
}