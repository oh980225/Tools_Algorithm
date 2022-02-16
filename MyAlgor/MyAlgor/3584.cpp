#include <bits/stdc++.h>

using namespace std;

int T, N;
int parents[10001];

int main() {
  cin >> T;

  while(T--) {
    cin >> N;

    int from, to;
    for(int i = 0; i < N - 1; i++) {
      cin >> from >> to;
      parents[to] = from;
    }

    int element1, element2;
    cin >> element1 >> element2;
    
    stack<int> s1, s2;
    while(parents[element1] != 0) {
      s1.push(element1);
      element1 = parents[element1];
    }
    s1.push(element1);

    while(parents[element2] != 0) {
      s2.push(element2);
      element2 = parents[element2];
    }
    s2.push(element2);

    int temp1, temp2;
    int ans = 0;
    while(s1.size() && s2.size()) {
      temp1 = s1.top();
      s1.pop();
      temp2 = s2.top();
      s2.pop();

      if(temp1 != temp2) {
        break;
      }
      ans = temp1;
    }

    cout << ans << '\n';
    memset(parents, 0, sizeof(parents));
  }

  return 0;
}