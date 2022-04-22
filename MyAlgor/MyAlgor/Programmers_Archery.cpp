#include <bits/stdc++.h>

using namespace std;

bool isOptimal(vector<int>& a, vector<int>& b){
  for(int i = 11; i >= 0; i--) {
    if(a[i] != b[i]) {
      return a[i] > b[i];
    }
  }

  return false;
}

void doAllCase(vector<int>& answer, vector<int>& info, int n) {
  for(int brute = 0; brute < 1024; brute++){
    vector<int> arrow(12);
    int score = 0;
    int remain = n; 

    for(int i = 0; i < 10; i++){
      if(brute & (1 << i)){ 
        score += (10 - i);
        remain -= (info[i] + 1);
        arrow[i] = info[i] + 1;
        continue;
      }

      if(info[i] != 0){ 
        score -= (10 - i);
      }
    }

    if(score <= 0 || remain < 0) {
      continue;
    }

    arrow[10] = remain;
    arrow[11] = score;
    
    if(isOptimal(arrow, answer)) {
      answer = arrow;
    }
  }

  answer.pop_back();
}

vector<int> solution(int n, vector<int> info) {
  vector<int> answer(12, -1);

  doAllCase(answer, info, n);

  if(answer[0] == -1) {
    return vector<int>({-1});
  }

  return answer;
}