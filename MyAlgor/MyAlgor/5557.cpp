#include <bits/stdc++.h>

using namespace std;

int N;
int numbers[101];
long long memo[101][21];

int main() {
  cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> numbers[i];
  }

  memo[1][numbers[1]]++;
  for(int i = 2; i < N; i++) {
    for(int j = 0; j <= 20; j++) {
      if(memo[i - 1][j]) {
        int plus = j + numbers[i];
        int minus = j - numbers[i];
        if(0 <= plus && plus <= 20) {
          memo[i][plus] += memo[i -1][j];
        }

        if(0 <= minus && minus <= 20) {
          memo[i][minus] += memo[i -1][j];
        }
      }
    }
  }

  cout << memo[N - 1][numbers[N]];

  return 0;
}