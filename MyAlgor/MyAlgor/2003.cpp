#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int N, M, result;

void input() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int num;
  for(int i = 0; i < N; i++) {
    cin >> num;
    A.push_back(num);
  }
}

void findM() {
  int l = 0;
  int r = 0;
  int sum = A[l];

  while(true) {
    if(r == N) {
      break;
    }

    if(sum < M) {
      r++;
      sum += A[r];
      continue;
    }

    if(sum > M) {
      sum -= A[l];
      l++;
      continue;
    }

    if(sum == M) {
      result++;
      sum -= A[l];
      l++;
    }
  }
}

void output() {
  cout << result;
}

int main() {
  input();

  findM();

  output();

  return 0;
}