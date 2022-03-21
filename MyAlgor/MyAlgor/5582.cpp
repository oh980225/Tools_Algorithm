#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int memo[4001][4001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str1 >> str2;

  int ans = 0;
  for(int i = 1; i <= str1.size(); i++) {
    for(int j = 1; j <= str2.size(); j++) {
      if(str1[i - 1] == str2[j - 1]) {
        memo[i][j] = memo[i - 1][j - 1] + 1;
        ans = max(ans, memo[i][j]);
      }
    }
  }

  cout << ans;

  return 0;
}