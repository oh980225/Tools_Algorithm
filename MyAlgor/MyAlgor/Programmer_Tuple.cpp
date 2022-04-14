#include <bits/stdc++.h>

using namespace std;

bool chk[100001];

vector<string> split(string input, char c) {
  vector<string> answer;
  stringstream ss(input);
  string temp;
 
  while (getline(ss, temp, c)) {
    answer.push_back(temp);
  }
 
  return answer;
}

void eraseFrontAndBack(string& s) {
  s.erase(0, 1);
  s.erase(s.size() - 1, 1);
}

vector<string> extractNumString(string& s) {
  vector<string> result;
  bool flag = false;
  int start = -1;
  int cnt = 0;

  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '{') {
      start = i + 1;
      flag = true;
    }

    if(flag) {
      if(s[i] == '}') {
        result.push_back(s.substr(start, cnt));
        flag = false;
        cnt = 0;
        start = -1;
      }

      cnt++;
    }
  }

  return result;
}

bool compare(vector<int> a, vector<int> b) {
  return a.size() < b.size();
}

void solve(vector<int>& ans, vector<string>& v) {
  vector<vector<int>> matrix;
  for(auto element : v) {
    vector<string> temp = split(element, ',');
    vector<int> nums;

    for(auto number : temp) {
      nums.push_back(stoi(number));
    }

    matrix.push_back(nums);
  }

  sort(matrix.begin(), matrix.end(), compare);

  for(auto element : matrix) {
    for(auto num : element) {
      if(!chk[num]) {
        chk[num] = true;
        ans.push_back(num);
      }
    }
  }
}

vector<int> solution(string s) {
  vector<int> answer;

  eraseFrontAndBack(s);

  vector<string> temp = extractNumString(s);

  solve(answer, temp);  

  return answer;
}