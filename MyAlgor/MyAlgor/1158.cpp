#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> v;

  queue<int> q;
  for(int i = 1; i <= N; i++) {
    q.push(i);
  }

  int count = 1;
  while(q.size()) {
    int cur = q.front();
    q.pop();
    if(count == K) {
      v.push_back(cur);
      count = 1;
      continue;
    }
    q.push(cur);
    count++;
  }
  cout << "<";

  for(int i = 0; i < v.size() - 1; i++) {
    cout << v[i] << ", ";
  }

  cout << v[v.size() - 1] << ">";
}