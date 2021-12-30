#include <iostream>
#include <queue>

using namespace std;

struct POS {
  int r, c;
};

POS start;
POS dest;
POS moveArr[] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
bool check[200][200];

int main() {
  int N;
  cin >> N;
  
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  start = {r1, c1};
  dest = {r2, c2};

  queue<pair<POS, int>> q;
  q.push({start, 0});
  check[r1][c1] = true;

  int result = -1;
  
  while(!q.empty()) {
    int curR = q.front().first.r;
    int curC = q.front().first.c;
    int count = q.front().second;
    q.pop();
 
    if(curR == dest.r && curC == dest.c) {
      result = count;
      break;
    }

    for(auto move : moveArr) {
      int newR = curR + move.r;
      int newC = curC + move.c;
      
      if(0 <= newR && newR < N && 0 <= newC && newC < N && !check[newR][newC]) {
        POS newPOS = {newR, newC};
        check[newR][newC] = true;
        q.push({newPOS, count + 1});
      }
    }
  }

  cout << result;
  return 0;
}