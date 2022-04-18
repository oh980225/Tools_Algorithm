#include <bits/stdc++.h>

using namespace std;

struct Point {
  int to, time;
};

struct Current {
  int position, totalTime, state;
};

bool operator < (Current a, Current b) {
  return a.totalTime > b.totalTime;
}

vector<Point> matrix[1024][1001];
vector<int> trapVector;

int findMinDist(int start, int end, int n, int stateSize) {
  vector<vector<int>> ans(1 << stateSize, vector<int>(n + 1, 1e9));
  ans[0][start] = 0;

  priority_queue<Current> pq;
  pq.push({start, 0, 0});
  
  while(pq.size()) {
    auto cur = pq.top();
    int curPosition = cur.position;
    int curTime = cur.totalTime;
    int curState = cur.state;
    pq.pop();

    if(curPosition == end) {
      return curTime;
    }

    if(trapVector[curPosition] != -1) {
      curState ^= (1 << trapVector[curPosition]); 
    }

    for(int i = 0; i < matrix[curState][curPosition].size(); i++) {
      Point next = matrix[curState][curPosition][i];
      if(ans[curState][next.to] > curTime + next.time) {
        ans[curState][next.to] = curTime + next.time;
        pq.push({next.to, curTime + next.time, curState});
      }
    }
  }

  return -1;
}

void findAllState(vector<vector<int>>& roads, int stateSize) {
  for(int state = 0; state < (1 << stateSize); state++) {
    for(auto road : roads) {
      int from = road[0];
      int to = road[1];
      int costTime = road[2];

      if(trapVector[from] != -1 || trapVector[to] != -1) {
        int left = (state & (1 << trapVector[from])) ? 1 : 0;
        int right = (state & (1 << trapVector[to])) ? 1 : 0;

        if(left ^ right) {
          swap(from, to);
        }
      }

      matrix[state][from].push_back({to, costTime});
    }
  }
}

void fillTrapVector(int n, vector<int>& traps) {
  trapVector = vector<int>(n + 1, -1);

  for(int i = 0; i < traps.size(); i++) {
    trapVector[traps[i]] = i;
  }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
  fillTrapVector(n, traps);

  int stateSize = traps.size();

  findAllState(roads, stateSize);

  return findMinDist(start, end, n, stateSize);
}