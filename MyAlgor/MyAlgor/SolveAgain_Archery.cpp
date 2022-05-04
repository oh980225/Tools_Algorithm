#include <bits/stdc++.h>

using namespace std;

int maxPoint;
vector<int> answer = vector<int>(11, 0);

void checkAllState(int n, vector<int>& info) {
  for(int state = 1023; 0 <= state; state--) {
    int curArrow = n;
    int curPoint = 0;
    vector<int> arrow = vector<int>(11, 0);

    for(int j = 0; j < 10; j++) {
      if(state & (1 << j)) {
        curPoint += (10 - j);
        curArrow -= (info[j] + 1);
        arrow[j] = info[j] + 1;
        continue;
      }
      if(info[j]) {
        curPoint -= (10 - j);
      }
    }

    if(curArrow >= 0 && curPoint > 0) {
      if(curPoint > maxPoint) {
        arrow[10] = curArrow;
        maxPoint = curPoint;
        answer = arrow;
      }
    }
  }
}

vector<int> solution(int n, vector<int> info) {
  checkAllState(n, info);

  if(!maxPoint) {
    return {-1};
  }

  return answer;
}