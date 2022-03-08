#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> diff;

bool compare(int a, int b) {
  return a > b;
}

int main() {
  cin >> N >> K;

  int height;
  int pre = 0;
  for(int i = 0 ; i < N; i++) {
    cin >> height;
    if(!i) {
      pre = height;
      continue;
    }
    diff.push_back(height - pre);
    pre = height;
  }

  sort(diff.begin(), diff.end(), compare);
  
  int ans = 0;
  for(int i = K - 1; i < diff.size(); i++) {
    ans += diff[i];
  }

  cout << ans;

  return 0;
}