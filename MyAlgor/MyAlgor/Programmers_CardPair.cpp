#include <bits/stdc++.h>

using namespace std;

bool chk[4][4];
int curY, curX;
vector<vector<int>> tempBoard;
int dY[] = {0, 0, -1, 1};
int dX[] = {-1, 1, 0, 0};

vector<int> cardsInBoard(vector<vector<int>>& board) {
  vector<bool> chkNumCards;
  chkNumCards = vector<bool>(7, false);

  vector<int> cards;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(board[i][j] && !chkNumCards[board[i][j]]) {
        chkNumCards[board[i][j]] = true;
      }
    }
  }

  for(int i = 1; i <= 6; i++) {
    if(chkNumCards[i]) {
      cards.push_back(i);
    }
  }

  return cards;
}

struct Pos {
  int y, x, cnt;
};

void initChkArr() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      chk[i][j] = false;
    }
  }
}

bool inBoard(int y, int x) {
  return 0 <= y && y < 4 && 0 <= x && x < 4;
}

int findCard(int target) {
  queue<Pos> posQ;
  initChkArr();
  posQ.push({curY, curX, 0});
  chk[curY][curX] = true;
  int count = 0;
  while(posQ.size()) {
    auto cur = posQ.front();
    posQ.pop();

    if(tempBoard[cur.y][cur.x] == target) {
      curY = cur.y;
      curX = cur.x;
      tempBoard[cur.y][cur.x] = 0;
      return cur.cnt + 1;
    }

    for(int i = 0; i < 4; i++) {
      int newY = cur.y + dY[i];
      int newX = cur.x + dX[i];
      if(inBoard(newY, newX) && !chk[newY][newX]) {
        chk[newY][newX] = true;
        posQ.push({newY, newX, cur.cnt + 1});
      }
    }

    for(int i = 0; i < 4; i++) {
      int newY = cur.y;
      int newX = cur.x;
      while(inBoard(newY + dY[i], newX + dX[i])) {
        newY += dY[i];
        newX += dX[i];
        if(tempBoard[newY][newX]) {
          break;
        }
      }

      if(!chk[newY][newX]) {
        chk[newY][newX] = true;
        posQ.push({newY, newX, cur.cnt + 1});
      }
    }
  }

  return -1;
}

int solution(vector<vector<int>> board, int r, int c) {
  int answer = 1e8;

  vector<int> cards = cardsInBoard(board);

  do {
    int curCount = 0;
    tempBoard = board;
    curY = r;
    curX = c;
    for(int i = 0; i < cards.size(); i++) {
      int targetCard = cards[i];
      
      curCount += findCard(targetCard);
      curCount += findCard(targetCard);
    }

    answer = min(answer, curCount);
  } while(next_permutation(cards.begin(), cards.end()));

  return answer;
}