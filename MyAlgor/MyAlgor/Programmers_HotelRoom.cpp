#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> m;

long long findEmptyRoom(long long x) {
  if(!m[x]) {
    m[x] = x + 1;
    return x;
  }

  return m[x] = findEmptyRoom(m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;

  for(auto number : room_number) {
    answer.push_back(findEmptyRoom(number));
  }

  return answer;
}