#include <bits/stdc++.h>

using namespace std;

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

struct POS {
  int y, x;
};
POS pos;
bool chk[1005][1005];
char matrix[1005][1005];
int T, w, h;
vector<POS> fire;
queue<POS> fireQ;

int bfs() {
  queue<POS> q;
  q.push(pos);
    
  int result = 0;
  while(q.size()) {
    int fireSize = fireQ.size();
    while(fireSize--) {
      auto curFire = fireQ.front();
      fireQ.pop();

      for(int i = 0; i < 4; i++) {
        int newY = curFire.y + dY[i];
        int newX = curFire.x + dX[i];

        if(0 <= newY && newY < h && 0 <= newX && newX < w) {
          if(matrix[newY][newX] != '#' && matrix[newY][newX] != '*') {
            matrix[newY][newX] = '*';
            fireQ.push({newY, newX});
          }
        }
      }
    }

    int qSize = q.size();
    while(qSize--) {
      auto curPos = q.front();
      q.pop();

      if(curPos.y == 0 || curPos.y == h - 1 || curPos.x == 0 || curPos.x == w - 1) 
        return result + 1;

      for(int i = 0 ; i < 4; i++) {
        int newY = curPos.y + dY[i];
        int newX  = curPos.x + dX[i];
        
        if(0 <= newY && newY < h && 0 <= newX && newX < w && !chk[newY][newX] && matrix[newY][newX] != '#' && matrix[newY][newX] != '*') {
          chk[newY][newX] = true;
          q.push({newY, newX});
        }
      }
    }
    result++;
  }

  return 0;
}

int main() {
  cin >> T;
  while(T--) {
    fireQ = queue<POS>();
    memset(chk, 0, sizeof(chk));
    cin >> w >> h;
    string input;
    for(int i = 0; i < h; i++) {
      cin >> input;
      for(int j = 0; j < input.size(); j++) {
        matrix[i][j] = input[j];
        if(matrix[i][j] == '@')
          pos = {i, j};

        if(matrix[i][j] == '*')
          fireQ.push({i, j});
      }      
    }

    int ans = bfs();
    if(ans) {
      cout << ans << '\n';
      continue;
    }
    cout << "IMPOSSIBLE" << "\n";
  }

  return 0;
}