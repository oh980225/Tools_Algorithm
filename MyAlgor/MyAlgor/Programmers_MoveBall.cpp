#include <bits/stdc++.h>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
  long long answer = 0;
  long long x1 = x;
  long long x2 = x;
  long long y1 = y;
  long long y2 = y;

  for(int i = queries.size() - 1; 0 <= i; i--) {
    if(queries[i][0] == 0) {
      if(y1) {
        y1 += queries[i][1];
      }
      y2 = (y2 + queries[i][1] < m) ? y2 + queries[i][1] : m - 1;
    }

    else if(queries[i][0] == 1) {
      y1 = (0 <= y1 - queries[i][1]) ? y1 - queries[i][1] : 0;
      if(y2 != m - 1) {
        y2 -= queries[i][1];
      }
    }

    else if(queries[i][0] == 2) {
      if(x1) {
        x1 += queries[i][1];
      }
      x2 = (x2 + queries[i][1] < n) ? x2 + queries[i][1] : n - 1;
    }

    else if(queries[i][0] == 3) {
      x1 = (0 <= x1 - queries[i][1]) ? x1 - queries[i][1] : 0;
      if(x2 != n - 1) {
        x2 -= queries[i][1];
      }
    }

    if(x1 > n - 1 || x2 < 0 || y1 > m - 1 || y2 < 0) {
      return answer;
    }
  }

  answer = (x2 - x1 + 1) * (y2 - y1 + 1);

  return answer;
}