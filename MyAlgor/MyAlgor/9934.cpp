#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> tree[11];
vector<int> numbers;

void dfs(int start, int end, int depth) {
  if(start > end) {
    return;
  }

  int mid = (start + end) / 2;
  tree[depth].push_back(numbers[mid]);

  dfs(start, mid - 1, depth + 1);
  dfs(mid + 1, end, depth + 1);
}

int main() {
  cin >> K;

  int number;
  for(int i = 0; i < pow(2, K) - 1; i++) {
    cin >> number;
    numbers.push_back(number);
  }

  dfs(0, pow(2, K) - 1, 0);

  for(int i = 0; i < K; i++) {
    for(auto element: tree[i]) {
      cout << element << " ";
    }
    cout << '\n';
  }

  return 0;
}