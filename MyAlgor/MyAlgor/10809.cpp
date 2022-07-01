#include <bits/stdc++.h>

using namespace std;

string input;

int main() {
  cin >> input;

  for(char ch = 'a'; ch <= 'z'; ch++) {
    auto it = find(input.begin(), input.end(), ch);
    if(it == input.end()) {
      cout << -1 << " ";
      continue;
    }
    cout << it - input.begin() << " ";
  }

  return 0;
}