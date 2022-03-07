#include <bits/stdc++.h>

using namespace std;

int N, M;
int memo[10001];

vector<int> woks;

int main() {
  cin >> N >> M;

  int size;
  for(int i = 0; i < M; i++) {
    cin >> size;
    woks.push_back(size);
  }

  sort(woks.begin(), woks.end());

  for(int i = 1; i <= N; i++) {
    memo[i] = 1e9;
  }

  memo[0] = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < M; j++) {
      int wok = woks[j];
      if(i < wok) {
        continue;
      }

      if(memo[i - wok] != 1e9) {
        memo[i] = min(memo[i], memo[i - wok] + 1);
      }

      for(int k = j + 1; k < M; k++) {
        int other = woks[k];
        if(wok + other > i || memo[i - (wok + other) == 1e9]) {
          continue;
        }

        memo[i] = min(memo[i], memo[i - (wok + other)] + 1);
      }
    }
  }

  if(memo[N] == 1e9) {
    cout << -1;
    return 0;
  }

  cout << memo[N];
  return 0;
}