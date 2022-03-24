#include <string>
#include <vector>

using namespace std;

// x1, x2가 행, y1, y2가 열
int x1, y1, x2, y2;
int matrix[101][101];
int ans;

void toUp(int curY, int curX, int pre) {
  if(curX == y1 && curY == x1) {
    return;
  }

  int preValue = matrix[curY][curX];
  matrix[curY][curX] = pre;
  ans = min(ans, preValue);

  toUp(curY - 1, curX, preValue);
}

void toLeft(int curY, int curX, int pre) {
  int preValue = matrix[curY][curX];
  matrix[curY][curX] = pre;
  ans = min(ans, preValue);

  if(curX == y1) {
    toUp(curY - 1, curX, preValue);
    return;
  }

  toLeft(curY, curX - 1, preValue);
}

void toDown(int curY, int curX, int pre) {
  int preValue = matrix[curY][curX];
  matrix[curY][curX] = pre;
  ans = min(ans, preValue);

  if(curY == x2) {
    toLeft(curY, curX - 1, preValue);
    return;
  }

  toDown(curY + 1, curX, preValue);
}

void toRight(int curY, int curX, int pre) {
  int preValue = matrix[curY][curX];
  matrix[curY][curX] = pre;
  ans = min(ans, preValue);

  if(curX == y2) {
    toDown(curY + 1, curX, preValue);
    return;
  }

  toRight(curY, curX + 1, preValue);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;
    
  int value = 1;
  for(int i = 1; i <= rows; i++) {
    for(int j = 1; j <= columns; j++) {
        matrix[i][j] = value;
        value++;
    }
  }
    
  for(auto query : queries) {
    x1 = query[0];
    y1 = query[1];
    x2 = query[2];
    y2 = query[3];

    ans = matrix[x1 + 1][y1];
    toRight(x1, y1, matrix[x1 + 1][y1]);
    answer.push_back(ans);
  }
    
  return answer;
}