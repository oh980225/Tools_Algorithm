#include <string>
#include <vector>

using namespace std;

int memo[1005][1005];

void record(vector<vector<int>>& skill) {
  for(auto element : skill) {
    int type = element[0];
    int r1 = element[1];
    int c1 = element[2];
    int r2 = element[3];
    int c2 = element[4];
    int degree = element[5];

    if(type == 1) {
      degree = -degree;
    }

    memo[r1][c1] += degree;
    memo[r1][c2 + 1] -= degree;
    memo[r2 + 1][c1] -= degree;
    memo[r2 + 1][c2 + 1] += degree;
  }
}

void cumulativeSum(int n, int m) {
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      memo[i][j] += memo[i - 1][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m - 1; j++) {
      memo[i][j + 1] += memo[i][j];
    }
  }
}

int nonDestruction(vector<vector<int>> board) {
  int result = 0;

  for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board[0].size(); j++) {
      if(memo[i][j] + board[i][j] > 0) {
        result++;
      }
    }
  }

  return result;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
  record(skill);

  int n = board.size();
  int m = board[0].size();

  cumulativeSum(n, m);

  return nonDestruction(board);
}