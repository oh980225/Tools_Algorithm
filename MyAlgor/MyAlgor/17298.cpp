#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> A;
stack<int> s;

int main() {
  cin >> N;

  int num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    A.push_back(num);
  }

  for(int i = 0; i < N; i++) {
    if(s.empty()) {
      s.push(i);
      continue;
    }

    while(A[i] > A[s.top()]) {
      A[s.top()] = A[i];
      s.pop();

      if(s.empty()) {
        break;
      }
    }

    s.push(i);
  }

  while(!s.empty()) {
    A[s.top()] = -1;
    s.pop();
  }

  for(int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }

  return 0;
}