#include <bits/stdc++.h>

using namespace std;

bool check[1505][1505];

void checkDevide(int A, int B, int C) {
  int sum = A + B + C;
  queue<pair<int, int>> q;
  q.push({A, B});
  check[A][B] = true;
  check[B][A] = true;

  if(sum % 3 != 0) {
    cout << "0";
    return;
  }

  while(!q.empty()) {
    int cur[3];
    cur[0] = q.front().first;
    cur[1] = q.front().second;
    cur[2] = sum - cur[0] - cur[1];
    q.pop();

    if(cur[0] == cur[1] && cur[1] == cur[2]) {
      cout << "1";
      return;
    }

    for(int i = 0; i < 2; i++) {
      for(int j = i + 1; j < 3; j++) {

        if(cur[i] < cur[j]) {
          int newB = cur[j] - cur[i];
          int newA = cur[i] * 2;
          if(check[newA][newB]) {
            continue;
          }
          check[newA][newB] = true;
          check[newB][newA] = true;
          q.push({newA, newB});
          continue;
        }

        if(cur[j] < cur[i]) {
          int newA =  cur[i] - cur[j];
          int newB = cur[j] * 2;
          if(check[newA][newB]) {
            continue;
          }
          check[newA][newB] = true;
          check[newB][newA] = true;
          q.push({newA, newB});
          continue;
        }
      }
    }
  }

  cout << "0";
  return;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  checkDevide(A, B, C);

  return 0;
}