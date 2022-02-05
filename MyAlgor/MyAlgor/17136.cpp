#include <bits/stdc++.h>

using namespace std;

int matrix[11][11];
int numArr[] = {0, 5, 5, 5, 5, 5};
int ans = INT_MAX;

bool chkPaper(int y, int x, int size) {
  for(int i = y; i < y + size; i++) 
    for(int j = x; j < x + size; j++) 
      if(!(0 <= i && i < 10 && 0 <= j && j < 10) || !matrix[i][j])
        return false;
  return true;
}

void stick(int y, int x, int size, int value) {
  for(int i = y; i < y + size; i++) 
    for(int j = x; j < x + size; j++) 
      matrix[i][j] = value;
}

// 위치, 현재 사용한 색종이 갯수
void dfs(int y, int x, int cnt) {
  if(ans <= cnt) 
    return;

  if(y >= 9 && x > 9) {
    ans = min(ans, cnt);
    return;
  }

  if(x > 9) {
    dfs(y + 1, 0, cnt);
    return;
  }

  if(matrix[y][x] == 1) {
    for(int i = 5; 1 <= i; i--) {
      // 색종이 붙힐 수 있는지 점검 + 해당 색종이 남았는지 점검
      if(chkPaper(y, x, i) && numArr[i]) {
        stick(y, x, i, 0);
        numArr[i]--;
        dfs(y, x + 1, cnt + 1);
        stick(y, x, i, 1);
        numArr[i]++;
      }
    }
    return;
  }
  dfs(y, x + 1, cnt);
}

int main() {
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      cin >> matrix[i][j];
  
  dfs(0, 0, 0);

  ans = (ans == INT_MAX) ? -1 : ans;
  cout << ans;

  return 0;
}