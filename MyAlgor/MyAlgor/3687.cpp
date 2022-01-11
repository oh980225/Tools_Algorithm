#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int T, n;
char minNum[8];
ll dpForMin[101];

void init() {
  minNum[2] = '1';
  minNum[3] = '7';
  minNum[4] = '4';
  minNum[5] = '2';
  minNum[6] = '0';
  minNum[7] = '8';
  dpForMin[2] = 1;
  dpForMin[3] = 7;
  dpForMin[4] = 4;
  dpForMin[5] = 2;
  dpForMin[6] = 6;
  dpForMin[7] = 8;
}

void prepareMin() {
  for(int i = 8; i <= 100; i++) {
    ll result  = __LONG_LONG_MAX__;

    for(int k = 2; k <= 7; k++) {
      if(i - k < 2) {
        break;
      }
      string str = to_string(dpForMin[i - k]);
      int size = str.size();
      str.push_back(minNum[k]);
      ll curResult = stoll(str);
      int intMinNum = minNum[k] - '0';
      string strMin = to_string(intMinNum);

      for(int j = 0; j < size; j++) {
        string temp = to_string(dpForMin[i - k]);
        if(j == 0 && strMin == "0") {
          continue;
        }
        temp.insert(j, strMin);
        ll curNum = stol(temp);
        curResult = min(curResult, curNum);
      }
      
      result = min(result, curResult);
    }

    dpForMin[i] = result;
  }
}

void getMax() {
  string str = "";

  if(n % 2 == 0) {
    for(int i = 0; i < n / 2; i++) {
      str.push_back('1');
    }
    cout << str << '\n';
    return;
  }

  str.push_back('7');
  for(int i = 0; i < (n - 3) / 2; i++) {
    str.push_back('1');
  }
  cout << str << '\n';
  return;
}

void getMin() {
  cout << dpForMin[n] << ' ';
}

int main() {
  init();
  prepareMin();

  cin >> T;

  while(T--) {
    cin >> n;
    getMin();
    getMax();
  }

  return 0;
}