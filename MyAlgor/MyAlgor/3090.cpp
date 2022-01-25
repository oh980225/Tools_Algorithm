#include <bits/stdc++.h>

using namespace std;

int N, T;
int arr[100001];
int copyArr[100001];
typedef long long ll;


bool possible(int mid) {
  ll cnt = 0;
  // memcpy(copyArr, arr, sizeof(arr));
  for(int i = 0; i < N; i++) {
    copyArr[i] = arr[i];
  }

  for(int i = 0; i < N - 1; i++) {
    int diff = copyArr[i + 1] - copyArr[i];
    if(diff > mid) {
      copyArr[i + 1] = copyArr[i] + mid;
      cnt += (diff - mid);
    }
  }

  for(int i = N - 1; 0 < i; i--) {
    int diff = copyArr[i - 1] - copyArr[i];
    if(diff > mid) {
      copyArr[i - 1] = copyArr[i] + mid;
      cnt += (diff - mid);
    }
  }

  return cnt <= T;
}

int main() {
  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int l = 0;
  int r = 1e9;
  while(l < r) {
    int mid = (l + r) / 2;
    if(possible(mid)) {
      r = mid;
      continue;
    }
    l = mid + 1;
  }

  for(int i = 0; i < N - 1; i++) {
    int diff = arr[i + 1] - arr[i];
    if(diff > r) 
      arr[i + 1] = arr[i] + r;
  }

  for(int i = N - 1; 0 < i; i--) {
    int diff = arr[i - 1] - arr[i];
    if(diff > r) 
      arr[i - 1] = arr[i] + r;
  }

  for(int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}