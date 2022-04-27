#include <string>
#include <vector>

using namespace std;

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

bool end(vector<vector<int>>& board, int y, int x) {
  int rowSize = board.size();
  int colSize = board[0].size();

  for(int i = 0; i < 4; i++) {
    int newY = y + dY[i];
    int newX = x + dX[i];
    if(0 <= newY && newY < rowSize && 0 <= newX && newX < colSize && board[newY][newX]) {
      return false;
    }
  }

  return true;
}

pair<bool, int> solve(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
  if(end(board, y1, x1)) {
    return {false, 0};
  }

  if(y1 == y2 && x1 == x2) {
    return {true, 1};
  }

  bool win = false;
  int minTurn = 1e9;
  int maxTurn = 0;

  int rowSize = board.size();
  int colSize = board[0].size();

  for(int i = 0; i < 4; i++) {
    int newY = y1 + dY[i];
    int newX = x1 + dX[i];
    if(0 <= newY && newY < rowSize && 0 <= newX && newX < colSize && board[newY][newX]) {
      board[y1][x1] = 0;
      pair<bool, int> result = solve(board, y2, x2, newY, newX);
      board[y1][x1] = 1;

      if(!result.first) {
        win = true;
        minTurn = min(minTurn, result.second);
        continue;
      }

      maxTurn = max(maxTurn, result.second);
    }
  }

  int turn = win ? minTurn : maxTurn;

  return {win, turn + 1};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
  return solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}