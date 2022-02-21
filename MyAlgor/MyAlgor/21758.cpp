#include <bits/stdc++.h>

using namespace std;

int N;
int honey[100001];

// 1부터 i까지 합
int toEnd[100001];

// N부터 i까지 합
int toStart[100001];


int main() {
  cin >> N;

  int amount;
  for(int i = 1; i <= N; i++) {
    cin >> amount;
    honey[i] = amount;
    toEnd[i] = toEnd[i - 1] + amount;
  }

  for(int i = 1; i <= N; i++) {
    toStart[i] = toEnd[N] - toEnd[i - 1];
  }

  // 왼쪽 끝에 벌통, 오른쪽 끝에 벌 하나
  int bee = toEnd[N] - honey[N];
  int temp = 0;
  for(int i = 2; i < N; i++) {
    if(temp < toEnd[i] - 2 * honey[i] + bee) {
      temp = toEnd[i] - 2 * honey[i] + bee;
    }
  }
  int answer = temp;

  // 오른쪽 끝에 벌통, 왼쪽 끝에 벌 하나
  bee = toEnd[N] - honey[1];
  temp = 0;
  for(int i = 2; i < N; i++) {
    if(temp < toStart[i] - 2 * honey[i] + bee) {
      temp = toStart[i] - 2 * honey[i] + bee;
    }
  }
  answer = max(temp, answer);

  // 양쪽 끝 벌, 가운데 어딘가 벌통
  temp = 0;
  for(int i = 2; i < N; i++) {
    temp = max(temp, toEnd[i] - honey[1] + toStart[i] - honey[N]);
  }
  answer = max(temp, answer);

  cout << answer;

  return 0;
}