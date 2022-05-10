#include <bits/stdc++.h>

using namespace std;

void moveIt(int start, int to) {
  cout << start << " " << to << '\n';
}

void hanoi(int cnt, int start, int to, int via) {
  if(cnt == 1) {
    moveIt(start, to);
    return;
  }

  hanoi(cnt - 1, start, via, to);
  moveIt(start, to);
  hanoi(cnt - 1, via, to, start);
}

int main() {
  int N;
  cin >> N;
  string answer = to_string(pow(2, N));
  int idx = answer.find('.');
  answer = answer.substr(0, idx);
  answer[answer.length() - 1] -= 1;

  cout << answer << '\n';

  if(N <= 20) {
    hanoi(N, 1, 3, 2);
  }
  
  return 0;
}