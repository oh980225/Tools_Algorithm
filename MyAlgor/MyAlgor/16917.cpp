#include <bits/stdc++.h>

using namespace std;

int A, B, C, X ,Y;

int main() {
  cin >> A >> B >> C >> X >> Y;

  if(A + B < 2 * C) {
    cout << A * X + B * Y;
    return 0;
  }

  if(X > Y) {
    cout << 2 * C * Y + min(A, 2 * C) * (X - Y);
    return 0;
  }

   
  cout << 2 * C * X + min(B, 2 * C) * (Y - X);
  return 0;
}