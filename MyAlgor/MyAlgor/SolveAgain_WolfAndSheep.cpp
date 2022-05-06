#include <bits/stdc++.h>

using namespace std;

vector<int> l(20, -1);
vector<int> r(20, -1);
bool chk[1 << 17];
vector<int> value;
int ans;

void makeTree(vector<vector<int>>& edges) {
  for(auto edge : edges) {
    int parent = edge[0];
    int child = edge[1];

    if(l[parent] == -1) {
      l[parent] = child;
      continue;
    }

    r[parent] = child;
  }
}

void findMaxSheep(int state) {
  if(chk[state]) {
    return;
  }
  chk[state] = true;

  int totalNum = 0;
  int wolfCnt = 0;
  for(int i = 0; i < value.size(); i++) {
    if(state & (1 << i)) {
      totalNum++;
      wolfCnt += value[i];
    }
  }

  if(wolfCnt * 2 >= totalNum) {
    return;
  }

  ans = max(ans, totalNum - wolfCnt);

  for(int i = 0; i < value.size(); i++) {
    if(!(state & (1 << i))) {
      continue;
    }
    
    if(l[i] != -1) {
      findMaxSheep(state | (1 << l[i]));
    }

    if(r[i] != -1) {
      findMaxSheep(state | (1 << r[i]));
    }
  }
}

int solution(vector<int> info, vector<vector<int>> edges) {
  value = info;

  makeTree(edges);

  findMaxSheep(1);

  return ans;
}