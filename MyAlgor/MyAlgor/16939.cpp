#include <bits/stdc++.h>

using namespace std;

int qube[25];

int FirstCondition[6][4] = {
  {1, 2, 17, 19}, 
  {3, 4, 13, 15}, 
  {5, 6, 7, 8}, 
  {11, 12, 14, 16}, 
  {9, 10, 18, 20}, 
  {21, 22, 23, 24}
};

int SecondCondition[6][4] = {
  {1, 2, 14, 16}, 
  {9, 10, 13, 15}, 
  {11, 12, 17, 19}, 
  {3, 4, 18, 20}, 
  {21, 22, 23, 24},  
  {5 ,6 ,7, 8}
};

int ThirdCondition[6][4] = {
  {1, 3, 6, 8}, 
  {5, 7, 10, 12}, 
  {9, 11, 21, 23}, 
  {2, 4, 22, 24}, 
  {17, 18, 19, 20},  
  {13, 14, 15, 16}
};

int FourthCondition[6][4] = {
  {1, 3, 21, 23}, 
  {2, 4, 5, 7}, 
  {6, 8, 9, 11}, 
  {10, 12, 22, 24}, 
  {13, 14, 15, 16}, 
  {17, 18, 19, 20}
};

int FifthCondition[6][4] = {
  {1, 2, 3, 4}, 
  {5, 6, 15, 16}, 
  {9, 10, 11, 12}, 
  {13, 14, 23, 24}, 
  {7, 8, 17, 18}, 
  {19, 20, 21, 22}
};

int SixthCondition[6][4] = {
  {1, 2, 3, 4}, 
  {5, 6, 19, 20}, 
  {9, 10, 11, 12}, 
  {17, 18, 23, 24}, 
  {7, 8, 13, 14}, 
  {15, 16, 21, 22}
};

bool checkCondition(int condition[6][4]) {
  bool temp = false;
  for(int i = 0; i < 6; i++) {
    if(!(qube[condition[i][0]] == qube[condition[i][1]] && 
    qube[condition[i][1]] == qube[condition[i][2]] &&
    qube[condition[i][2]] == qube[condition[i][3]])) {
      temp = true;
      break;
    }
  }

  if(temp) {
    return false;
  }

  return true;
}

int main() {
  for(int i = 1; i <= 24; i++) {
    cin >> qube[i];
  }

  if(checkCondition(FirstCondition) ||
  checkCondition(SecondCondition) ||
  checkCondition(ThirdCondition) ||
  checkCondition(FourthCondition) ||
  checkCondition(FifthCondition) ||
  checkCondition(SixthCondition)
  ) {
    cout << 1;
    return 0;
  }

  cout << 0;
  return 0;
}