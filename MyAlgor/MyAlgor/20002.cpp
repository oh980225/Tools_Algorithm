#include <bits/stdc++.h>

using namespace std;

int matrix[301][301];
int sum[301][301];
int N;
int result = INT_MIN;

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) 
    for(int j = 1; j <= N; j++) 
      cin >> matrix[i][j];
}

void calculateSum() {
for(int i = 1; i <= N; i++) 
    for(int j = 1; j <= N; j++) 
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
}

void calculateMaxBenefit() {
  for(int k = 1; k <= N; k++) {
    for(int i = 0; i + k <= N; i++) {
      for(int j = 0; j + k <= N; j++) {
        int benefit = sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j];
        result = max(result, benefit);
      }
    }
  }
}

void output() {
  cout << result;
}

int main() {
  input();

  calculateSum();

  calculateMaxBenefit();

  output();

  return 0;
}