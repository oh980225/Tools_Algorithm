#include <bits/stdc++.h>

using namespace std;

bool isSnake[101];
bool isLadder[101];
int moves[101];
bool check[101];
struct SPACE {
  int number, count;
};

void input() {
  int N, M;

  cin >> N >> M;

  int start, end;
  for(int i = 0; i < N; i++) {
    cin >> start >> end;
    isLadder[start] = true;
    moves[start] = end;
  }

  for(int i = 0; i < M; i++) {
    cin >> start >> end;
    isSnake[start] = true;
    moves[start] = end;
  }
}

int playGame() {
  queue<SPACE> q;
  q.push({1, 0});
  check[1] = true;

  while(!q.empty()) {
    int curNumber = q.front().number;
    int curCount = q.front().count;
    q.pop();

    if(curNumber == 100) {
      return curCount;
    }

    if(isLadder[curNumber]) {
      curNumber = moves[curNumber];
    }

    if(isSnake[curNumber]) {
      curNumber = moves[curNumber];
    }

    for(int i = 1; i <= 6; i++) {
      if((curNumber + i) <= 100 && !check[curNumber + i]) {
        check[curNumber + i] = true;
        q.push({curNumber + i, curCount + 1});
      }
    }
  }

  return -1;
}

int main() {
  input();

  int result = playGame();

  cout << result;
  return 0;
}