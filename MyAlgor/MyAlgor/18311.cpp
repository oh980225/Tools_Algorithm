#include <bits/stdc++.h>

using namespace std;

long long N, K;

vector<int> v;

int main() {
  cin >> N >> K;

  int course;
  for(int i = 0; i < N; i++) {
    cin >> course;
    v.push_back(course);
  }

  for(int i = 0; i < N; i++) {
    K -= v[i];
    if(K < 0) {
      cout << i + 1;
      return 0;
    }
  }

  for(int i = N - 1; i >= 0; i--) {
    K -= v[i];
    if(K <= 0) {
      cout << i + 1;
      return 0;
    }
  }

  return 0;
}