#include <bits/stdc++.h>

using namespace std;

int nodeCount;
int l[20];
int r[20];
int value[20];
bool chk[1 << 17];
int ans;

void dfs(int state) {
  if(chk[state]) {
    return;
  }
  chk[state] = 1;
  int wolfCnt = 0;
  int totalNum = 0;
  
  for(int i = 0; i < nodeCount; i++) {
    if(state & (1 << i)) {
      totalNum++;
      wolfCnt += value[i];
    }
  }

  if(2 * wolfCnt >= totalNum) {
    return;
  }

  ans = max(ans, totalNum - wolfCnt);
  for(int i = 0; i < nodeCount; i++) {
    if(!(state & (1 << i))) {
      continue;
    }

    if(l[i] != -1) {
      dfs(state | (1 << l[i]));
    }

    if(r[i] != -1) {
      dfs(state | (1 << r[i]));
    }
  }
}

void makeTree(vector<vector<int>>& edges) {
  for(int i = 0; i < edges.size(); i++) {
    int parent = edges[i][0];
    int child = edges[i][1];

    if(l[parent] == -1) {
      l[parent] = child;
      continue;
    }

    r[parent] = child;
  }
}

int solution(vector<int> info, vector<vector<int>> edges) {
  nodeCount = info.size();
  fill(l, l + nodeCount, -1);
  fill(r, r + nodeCount, -1);

  for(int i = 0; i < nodeCount; i++) {
    value[i] = info[i];
  }

  makeTree(edges);

  dfs(1);

  return ans;
}