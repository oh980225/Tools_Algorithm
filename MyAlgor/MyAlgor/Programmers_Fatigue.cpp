#include <bits/stdc++.h>

using namespace std;

bool chk[10];
vector<vector<int>> v;
int ans;

void dfs(int curK, int count) {
  ans = max(ans, count);
  for(int i = 0; i < v.size(); i++) {
    if(curK >= v[i][0] && !chk[i]) {
      chk[i] = true;
      dfs(curK - v[i][1], count + 1);
      chk[i] = false;
    }
  }
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;

    dfs(k, 0);

    return ans;
}