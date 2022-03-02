#include <bits/stdc++.h>

using namespace std;

int C, N;
vector<pair<int, int>> city;
int memo[100001];

int main() {
  cin >> C >> N;

  int cost, count;
  for(int i = 0; i < N; i++) {
    cin >> cost >> count;
    city.push_back({cost, count});
  }

  for(int i = 0; i < city.size(); i++) {
    for(int j = 1; j <= 100000; j++) {
      if(j >= city[i].first) {
        memo[j] = max(memo[j - city[i].first] + city[i].second, memo[j]);
      }
    }
  }

  for(int i = 1; i <= 100000; i++) {
    if(memo[i] >= C) {
      cout << i;
      return 0;
    }
  }

  return 0;
}