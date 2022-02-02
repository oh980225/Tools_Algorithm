#include <bits/stdc++.h>

using namespace std;

int N;
string scroll;
string angel;
string evil;
int flag = 0;
int dp[2][101][21];


int main() {
  cin >> scroll;
  cin >> evil;
  cin >> angel;

  // flag가 0이면 evil
  // flag가 1이면 angel
  for(int i = 0; i <= angel.size(); i++) {
    dp[0][i][0] = 1;
    dp[1][i][0] = 1;
  }

  for(int i = 1; i <= angel.size(); i++) {
    for(int j = 1; j <= scroll.size();j ++) {
      if(angel[i - 1] == scroll[j - 1])
        dp[1][i][j] += dp[0][i - 1][j - 1];
      if(evil[i - 1] == scroll[j - 1])
        dp[0][i][j] += dp[1][i - 1][j - 1];

      dp[1][i][j] += dp[1][i - 1][j];
      dp[0][i][j] += dp[0][i - 1][j];
    }
  }

  cout << dp[1][angel.size()][scroll.size()] + dp[0][angel.size()][scroll.size()];

  return 0;
}