#include <bits/stdc++.h>

using namespace std;

int C;
int position[11][11];
bool chk[11];
int result;

void dfs(int num, int value) {
  if(num == 11) {
    result = max(result, value);
    return;
  }
  
  for(int i = 0; i < 11; i++) {
    if(position[num][i] && !chk[i]) {
      chk[i] = true;
      dfs(num + 1, value + position[num][i]);
      chk[i] = false;
    }
  }
}

int main() {
  cin >> C;

  while(C--) {
    result = 0;
    for(int i = 0; i < 11; i++) {
      for(int j = 0; j < 11; j++) {
        cin >> position[i][j];
      }
    }
    memset(chk, 0, sizeof(chk));

    dfs(0, 0);
    cout << result << '\n';
  }

  return 0;
}