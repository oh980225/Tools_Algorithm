#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin >> N;

  int start, end;
  for(int i = 0; i < N; i++) {
    cin >> start >> end;
    v.push_back({start, end});
  }

  sort(v.begin(), v.end());

  int result = 1;
  pq.push(v[0].second);
  for(int i = 1; i < N; i++) {
    while(pq.size() && pq.top() <= v[i].first)
      pq.pop();
    pq.push(v[i].second);
    result = max(result, (int)pq.size());
  }

  cout << result;

  return 0;
}