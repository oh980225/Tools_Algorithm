#include <bits/stdc++.h>

using namespace std;

int T, K;

int sizeArr[501];
int sum[501];
int memo[501][501];

int main() {
  cin >> T;

  while(T--) {
    cin >> K;

    for(int i = 1; i <= K; i++) {
      cin >> sizeArr[i];
      sum[i] = sum[i - 1] + sizeArr[i];
    }

    for(int i = 1; i <= K - 1; i++) {
      for(int j = 1; i + j <= K; j++) {
        memo[j][i + j] = 1e9;
        for(int k = j; k < i + j; k++) {
          memo[j][i + j] = min(memo[j][i + j], memo[j][k] + memo[k + 1][i + j] + sum[i + j] - sum[j - 1]);
        }
      }
    }

    cout << memo[1][K] << '\n';
  }

  return 0;
}