#include <bits/stdc++.h>

using namespace std;

int T, k, n;
int teams[4][1001];
int result;


void selectStudent(int element, int idx, vector<int>& v2) {
  if(idx < 0)
    return;

  int temp = element + v2[idx];
  if(abs(temp - k) < abs(result - k)) {
    result = temp;
    return;
  }

  if(abs(temp - k) == abs(result - k)) 
    if(temp < result)
      result = temp;
}

void inputAndSelectStudent() {
  cin >> T;

  while(T--) {
    result = INT_MAX;
    cin >> k >> n;
    int num;
    for(int i = 0; i < 4; i++) 
      for(int j = 0; j < n; j++)
        cin >> teams[i][j];

    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        v1.push_back(teams[0][i] + teams[1][j]);

    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) 
        v2.push_back(teams[2][i] + teams[3][j]);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(auto element : v1) {
      int diff = k - element;
      auto iter = lower_bound(v2.begin(), v2.end(), diff);
      int idx = iter - v2.begin();
      selectStudent(element, idx, v2);
      selectStudent(element, idx - 1, v2);
      if(result == k) {
        break;
      }
    }
    cout << result << '\n';
    // v1.clear();
    // v2.clear();
  }
}

int main() {
  inputAndSelectStudent();

  return 0;
}