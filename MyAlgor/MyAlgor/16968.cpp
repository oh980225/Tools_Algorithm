#include <bits/stdc++.h>

using namespace std;

string input;

int main() {
  cin >> input;

  int c = 26;
  int d = 10;
  int ans = 0;

  if(input[0] == 'c') {
    ans = c;
  }
  else {
    ans = d;
  }

  for(int i = 1; i < input.size(); i++) {
    if(input[i] == 'c') {
      if(input[i - 1] == 'c') {
        ans *= (c - 1);
      }
      else {
        ans *= c;
      }
    }

    if(input[i] == 'd') {
      if(input[i - 1] == 'd') {
        ans *= (d - 1);
      }
      else {
        ans *= d;
      }
    }
  }

  cout << ans;
  
  return 0;
}