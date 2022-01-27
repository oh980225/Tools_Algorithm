#include <bits/stdc++.h>

using namespace std;

int N, M;
int lectures[100001];

bool possible(int mid) {
  int groupCnt = 1;
  int temp = 0;

  for(int i = 0; i < N; i++) {
    temp += lectures[i];

    if(temp > mid) {
      temp = lectures[i];
      groupCnt++;
    }
  }
  
  return groupCnt <= M;
}

int main() {
  cin >> N >> M;

  int maxLen = -1 ;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> lectures[i];
    maxLen = max(maxLen, lectures[i]);
    sum += lectures[i];
  }

  int l = maxLen;
  int r = sum;

  while(l <= r) {
    int mid = (l + r) / 2;
    if(possible(mid)) {
      r = mid - 1;
      continue;
    }
    l = mid + 1;
  }

  cout << l;

  return 0;
}