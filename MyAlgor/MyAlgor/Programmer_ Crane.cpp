#include <bits/stdc++.h>

using namespace std;

vector<stack<int>> stacks;
stack<int> bucket;
int answer;

void putBucket(int x) {
  if(bucket.size()) {
    int curTop = bucket.top();
    if(curTop == x) {
      answer += 2;
      bucket.pop();
      return;
    }
  }

  bucket.push(x);
}

int solution(vector<vector<int>> board, vector<int> moves) {
  int boardSize= board.size();
  stacks.resize(boardSize + 1);

  for(int i = 1; i <= boardSize; i++) {
    stack<int> s;
    for(int j = boardSize - 1; 0 <= j; j--) {
      if(board[j][i - 1]) {
        s.push(board[j][i - 1]);
      }
    }

    stacks[i] = s;
  }

  for(auto element : moves) {
    if(stacks[element].size()) {
      putBucket(stacks[element].top());
      stacks[element].pop();
    }
  }

  return answer;
}