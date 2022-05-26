#include <bits/stdc++.h>

using namespace std;

char matrix[505][505];
int chk[505][505];
bool possible[250005];
int ans;

int N, M;

void dfs(int y, int x, int cnt, int num) {
  if(y < 1 || y > N || x < 1 || x > M) {
    possible[num] = true;
    ans += cnt;
    return;
  }

  chk[y][x] = num;

  switch (matrix[y][x]) {
    case 'D':
      if(!chk[y + 1][x]) {
        dfs(y + 1, x, cnt + 1, num);
        break;
      }
      if(possible[chk[y + 1][x]]) {
        possible[chk[y][x]] = true;
        ans += (cnt + 1);
        return;
      }
      break;
  
    case 'U':
      if(!chk[y - 1][x]) {
        dfs(y - 1, x, cnt + 1, num);
        break;
      }
      if(possible[chk[y - 1][x]]) {
        possible[chk[y][x]] = true;
        ans += (cnt + 1);
        return;
      }
      break;

    case 'R':
      if(!chk[y][x + 1]) {
        dfs(y, x + 1, cnt + 1, num);
        break;
      }
      if(possible[chk[y][x + 1]]) {
        possible[chk[y][x]] = true;
        ans += (cnt + 1);
        return;
      }
      break;

    case 'L':
      if(!chk[y][x - 1]) {
        dfs(y, x - 1, cnt + 1, num);
        break;
      }
      if(possible[chk[y][x - 1]]) {
        possible[chk[y][x]] = true;
        ans += (cnt + 1);
        return;
      }
      break;
    default:
      break;
  }

  return;
}

int main() {
  cin >> N >> M;

  string input;
  for(int i = 1; i <= N; i++) {
    cin >> input;
    for(int j = 1; j <= M; j++) {
      matrix[i][j] = input[j - 1];
    }
  }

  int idx = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(!chk[i][j]) {
        dfs(i, j, 0, idx++);
      }
    }
  }

  cout << ans;

  return 0;
}