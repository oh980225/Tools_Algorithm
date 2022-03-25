#include <bits/stdc++.h>

using namespace std;

map<string, string> refer;
map<string, int> profit;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  vector<int> answer;

  for(int i = 0; i < enroll.size(); i++) {
    refer[enroll[i]] = referral[i];
  }

  for(int i = 0; i < seller.size(); i++) {
    string curSeller = seller[i];
    int curMoney = amount[i] * 100;

    while(true) {
      int fee = floor(curMoney * 0.1);
      if(fee < 1) {
        profit[curSeller] += curMoney;
        break;
      }

      profit[curSeller] += (curMoney - fee);
      curMoney = fee;
      curSeller = refer[curSeller];

      if(curSeller == "-") {
        break;
      }
    }
  }

  for(int i = 0; i < enroll.size(); i++) {
    answer.push_back(profit[enroll[i]]);
  }

  return answer;
}