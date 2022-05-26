#include <bits/stdc++.h>

using namespace std;

int line[2][100001];
bool chk[2][100001];

struct Pos {
  int lineNum, num, sec;
};

int main() {
  int N, k;

  cin >> N >> k;

  string input;

  cin >> input;
  for(int i = 0; i < N; i++) {
    line[0][i] = input[i] - '0';
  }

  cin >> input;
  for(int i = 0; i < N; i++) {
    line[1][i] = input[i] - '0';
  }

  queue<Pos> q;
  q.push({0, 0, 0});
  chk[0][0] = true;

  while(q.size()) {
    auto cur = q.front();
    q.pop();

    if(cur.num >= N) {
      cout << 1;
      return 0;
    }

    // 1.
    if(cur.num + 1 >= N || (!chk[cur.lineNum][cur.num + 1] && line[cur.lineNum][cur.num + 1])) {
      if(cur.num + 1 < N) {
        chk[cur.lineNum][cur.num + 1] = true;
      }
      
      q.push({cur.lineNum, cur.num + 1, cur.sec + 1});
    }

    // 2.
    if(cur.num > 0 && !chk[cur.lineNum][cur.num - 1] && line[cur.lineNum][cur.num - 1]) {
      chk[cur.lineNum][cur.num - 1] = true;
      q.push({cur.lineNum, cur.num - 1, cur.sec + 1});
    }

    // 3.
    if(cur.num + k >= N || (!chk[!cur.lineNum][cur.num + k] && line[!cur.lineNum][cur.num + k])) {
      if(cur.num + k < N) {
        chk[!cur.lineNum][cur.num + k] = true;
      }

      q.push({!cur.lineNum, cur.num + k, cur.sec + 1});
    }

    // remove
    line[0][cur.sec] = 0;
    line[1][cur.sec] = 0;
  }

  cout << 0;

  return 0;
}