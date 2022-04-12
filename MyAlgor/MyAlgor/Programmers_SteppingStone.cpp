#include <bits/stdc++.h>

using namespace std;

bool checkPass(vector<int>& stones, int k, int mid) {
  int cnt = 0;
  for(int i = 0; i < stones.size(); i++) {
    if(stones[i] - mid + 1 <= 0) {
      cnt++;
      if(cnt >= k) {
        return false;
      }
      continue;
    }

    cnt = 0;
  }
  return true;
}

int solution(vector<int> stones, int k) {
  int answer = 0;
  int left = 1;
  int right = *max_element(stones.begin(), stones.end());

  while(left <= right) {
    int mid = (left + right) / 2;

    if(checkPass(stones, k, mid)) {
      answer = mid;
      left = mid + 1;
      continue;
    }

    right = mid - 1;
  }

  return answer;
}