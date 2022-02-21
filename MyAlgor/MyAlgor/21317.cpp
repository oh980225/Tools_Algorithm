#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> stones;
int ans = 1e9;

void dfs(int curPos, int curCost, bool superJump) {
  if(curPos == N) {
    ans = min(ans, curCost);
    return;
  }
  if(curPos > N) {
    return;
  }

  // 작은 점프하는 경우
  dfs(curPos + 1, curCost + stones[curPos].first, superJump);

  // 큰 점프하는 경우
  dfs(curPos + 2, curCost + stones[curPos].second, superJump);

  // 슈퍼 점프 하는 경우(가능한 경우만!)
  if(!superJump) {
    dfs(curPos + 3, curCost + K, true);
  }
}

int main() {
  cin >> N;

  int small, big;
  stones.push_back({0, 0});
  for(int i = 0; i < N - 1; i++) {
    cin >> small >> big;
    stones.push_back({small, big});
  }
  
  cin >> K;

  dfs(1, 0, false);

  cout << ans;

  return 0;
}