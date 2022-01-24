#include <bits/stdc++.h>

using namespace std;

int T, w, h;
char fire[1005][1005];
bool chk[1005][1005];

int dY[] = {0, 0, 1, -1};
int dX[] = {1, -1, 0 ,0};

struct POS {
  int y, x;
};
queue<POS> firePos;
POS pos;

void spreadFire()  {
  int fireSize = firePos.size();
  while(fireSize--) {
    auto curFire = firePos.front();
    firePos.pop();

    for(int k = 0; k < 4; k++) {
      int newY = curFire.y+ dY[k];
      int newX = curFire.x + dX[k];
      if(1 <= newY && newY <= h && 1 <= newX && newX <= w && fire[newY][newX] != '#' && fire[newY][newX] != '*') {
        fire[newY][newX] = '*';
        firePos.push({newY, newX});
      }
    }
  }
}

int main() {
  cin >> T;
  while(T--) {
    memset(chk, 0, sizeof(chk));
    firePos = queue<POS>();

    // input
    cin >> w >> h;
    for(int i = 1; i <= h; i++) {
      string input;
      cin >> input;
      for(int j = 0; j < input.size(); j++) {
        if(input[j] == '@') {
          pos = {i, j + 1};
          continue;
        }
        if(input[j] == '*')
          firePos.push({i, j + 1});

        fire[i][j + 1] = input[j];
      }
    }

    queue<pair<POS, int>> q;
    q.push({pos, 0});
    chk[pos.y][pos.x] = true;
    int result = -1;
    while(q.size()) {
      auto cur = q.front();
      q.pop();

      if(!(1 <= cur.first.y && cur.first.y <= h && 1 <= cur.first.x && cur.first.x <= w)) {
        result = cur.second;
        break;
      }

      // 불을 퍼뜨린다.
      spreadFire();

      // 이동한다.
      for(int i = 0; i < 4; i++) {
        int newY = cur.first.y + dY[i];
        int newX = cur.first.x + dX[i];
        if(fire[newY][newX] != '#' && fire[newY][newX] != '*' && !chk[newY][newX]) {
          chk[newY][newX] = true;
          q.push({{newY, newX}, cur.second + 1});
        }
      }
    }
    if(result != -1) {
      cout << result << '\n';
      continue;
    }
    cout << "IMPOSSIBLE\n";
  }
  
  return 0;
}