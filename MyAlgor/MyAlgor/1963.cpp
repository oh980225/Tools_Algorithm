#include <bits/stdc++.h>

using namespace std;

int T;

bool chkPrime[100000];
int chk[100000];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  chk[s] = 0;

  while(q.size()) {
    int front = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      string strNum = to_string(front);
      for(int j = 0; j < 10; j++) {
        strNum[i] = j + '0';
        int next = stoi(strNum);
        if(1000 <= next && chkPrime[next] && chk[next] == -1) {
          chk[next] = chk[front] + 1;
          q.push(next);
        }
      }
    }
  }
}

int main() {
  cin >> T;

  int startNum;
  int endNum;

  memset(chkPrime, true, sizeof(chkPrime));
  for(int i = 2; i <= sqrt(9999); i++) {
    for(int j = i * i; j <= 9999; j+=i) {
      chkPrime[j] = false;
    }
  }

  while(T--) {
    cin >> startNum;
    cin >> endNum;

    memset(chk, -1, sizeof(chk));
    bfs(startNum);

    if(chk[endNum] == -1) {
      cout << "Impossible\n";
      continue;
    }

    cout << chk[endNum] << '\n';
  }

  return 0;
}