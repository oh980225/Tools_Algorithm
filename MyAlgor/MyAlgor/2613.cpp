#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

bool possible(int mid) {
  int sum = 0;
  int cnt = 1;
  for(int i = 0; i < N; i++) {
    sum += v[i];
    if(sum > mid) {
      sum = v[i];
      cnt++;
    }
  }
  return cnt <= M;
}

int main() {
  cin >> N >> M;

  int num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    v.push_back(num);
  }

  int l = *max_element(v.begin(), v.end());
  int r = accumulate(v.begin(), v.end(), 0);
  while(l <= r) {
    int mid = (l + r) / 2;
    if(possible(mid)) {
      r = mid - 1;
      continue;
    }
    l = mid + 1;
  }

  cout << l << '\n';
  int sum = 0;
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    sum += v[i];
    if(sum > l) {
      sum = v[i];
      M--;
      cout << cnt << " ";
      cnt = 0;
    }
    cnt++;
    if(N - i == M)
      break;
  }

  while(M--) {
    cout << cnt << " ";
    cnt = 1;
  }

  return 0;
}