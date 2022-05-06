#include <bits/stdc++.h>

using namespace std;

struct Point {
  int to, w;
};

struct Cur {
  int position, w, state;
};

bool operator < (Cur a, Cur b) {
  return a.w > b.w;
}

vector<int> trapV;
vector<Point> matrix[1024][1001];
int pointCount;
int stateSize;

void fillTrapV(vector<int>& traps) {
  trapV = vector<int>(pointCount + 1, -1);

  for(int i = 0; i < traps.size(); i++) {
    trapV[traps[i]] = i;
  }
}

void recordAllRoadState(vector<vector<int>>& roads) {
  for(int state = 0; state < (1 << stateSize); state++) {
    for(auto road : roads) {
      int from = road[0];
      int to = road[1];
      int cost = road[2];

      int left = (state & (1 << trapV[from])) ? 1 : 0;
      int right = (state & (1 << trapV[to])) ? 1 : 0;
      if(left ^ right) {
        swap(from, to);
      }

      matrix[state][from].push_back({to, cost});
    }
  }
}

int getMinPath(int start, int end) {
  vector<vector<int>> ans(1 << stateSize, vector<int>(pointCount + 1, 1e8));
  vector<vector<bool>> chk(1 << stateSize, vector<bool>(pointCount + 1, false));

  priority_queue<Cur> pq;
  ans[0][start] = 0;
  pq.push({start, 0, 0});

  while(pq.size()) {
    auto cur = pq.top();
    int curPosition = cur.position;
    int curW = cur.w;
    int curState = cur.state;
    pq.pop();

    if(chk[curState][curPosition]) {
      continue;
    }
    chk[curState][curPosition] = true;

    if(curPosition == end) {
      return curW;
    }

    if(trapV[curPosition] != -1) {
      curState ^= (1 << trapV[curPosition]);
    }

    for(int i = 0; i < matrix[curState][curPosition].size(); i++) {
      auto next = matrix[curState][curPosition][i];
      if(ans[curState][next.to] > curW + next.w) {
        ans[curState][next.to] = curW + next.w;
        pq.push({next.to, curW + next.w, curState});
      }
    }
  }

  return -1;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
  pointCount = n;
  stateSize = traps.size();

  fillTrapV(traps);

  recordAllRoadState(roads);

  return getMinPath(start, end);
}