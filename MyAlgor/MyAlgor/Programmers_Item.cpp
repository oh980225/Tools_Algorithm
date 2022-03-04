#include <bits/stdc++.h>

using namespace std;

int matrix[110][110];

int dY[] = {0, 0, 1, -1};
int dX[] = {1, -1, 0, 0};
vector<vector<int>> v;

bool in(int y, int x) {
  for(auto element : v) {
    int leftLowX = element[0] * 2;
    int leftLowY = element[1] * 2;
    int rightHighX = element[2] * 2;
    int rightHighY = element[3] * 2;
    if(leftLowY < y && y < rightHighY && leftLowX < x && x < rightHighX) {
      return true;
    }
  }
  return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
  characterX *= 2;
  characterY *= 2;
  itemX *= 2;
  itemY *= 2;
  v = rectangle;
  int answer = 0;
    
  for(auto element : rectangle) {
    int leftLowX = element[0] * 2;
    int leftLowY = element[1] * 2;
    int rightHighX = element[2] * 2;
    int rightHighY = element[3] * 2;
    for(int i = leftLowY; i <= rightHighY; i++) {
      for(int j = leftLowX; j <= rightHighX; j++) {
        matrix[i][j] = -1;
      }
    }
  }
    
  queue<pair<pair<int, int>, int>> q;
  q.push({{characterY, characterX}, 0});
  matrix[characterY][characterX] = 0;
    
  while(q.size()) {
    auto cur = q.front();
    q.pop();
        
    if(cur.first.first == itemY && cur.first.second == itemX) {
      answer = cur.second / 2;
      break;
    }
        
    for(int i = 0; i < 4; i++) {
      int newY = cur.first.first + dY[i];
      int newX = cur.first.second + dX[i];
      if(matrix[newY][newX] < 0 && !in(newY, newX)) {
        matrix[newY][newX] = 0;
        q.push({{newY, newX}, cur.second + 1});
      }
    }
  }
    
  return answer;
}