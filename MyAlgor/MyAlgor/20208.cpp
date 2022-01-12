#include <bits/stdc++.h>

using namespace std;

int N, M, H, result;

int matrix[11][11];
vector<pair<int, int>> mint;
int homeY = -1;
int homeX = -1;

void input() {
  cin >> N >> M >> H;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> matrix[i][j];
      if(matrix[i][j] == 1) {
        homeY = i;
        homeX = j;
      }
      if(matrix[i][j] == 2) {
        mint.push_back({i, j});
      }
    }
  }
}

void findMint(int y, int x, int health, int cnt) {
  if(cnt > result) {
    int backDistance = abs(y - homeY) + abs(x - homeX);

    if(backDistance <= health) 
      result = cnt;
  }

  for(int i = 0; i < mint.size(); i++) {
    auto mintPos = mint[i];

    if(!matrix[mintPos.first][mintPos.second]) {
      continue;
    }

    int distance = abs(y - mint[i].first) + abs(x - mint[i].second);

    if(distance <= health) {
      matrix[mintPos.first][mintPos.second] = 0;
      findMint(mintPos.first, mintPos.second, health - distance + H, cnt + 1);
      matrix[mintPos.first][mintPos.second] = 2;
    }
  }
}

void output() {
  cout << result;
}

int main() {
  input();

  findMint(homeY, homeX, M, 0);

  output();

  return 0;
}