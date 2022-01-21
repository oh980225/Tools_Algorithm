#include <bits/stdc++.h>

using namespace std;

int N;

int memo[100001];
int people[100001];

int main() {
  cin >> N;

  int startTime, endTime, count;
  for(int i = 1; i <= N; i++) {
    cin >> startTime >> endTime >> count;
    people[i] = count;
  }

  memo[1] = people[1];

  for(int i = 2; i <= N; i++) {
    memo[i] = max(memo[i - 1], memo[i - 2] + people[i]);
  }

  cout << memo[N];

  return 0;
}