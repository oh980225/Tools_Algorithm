#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

vector<string> split(string input, char delimiter) {
  vector<string> answer;
  stringstream ss(input);
  string temp;
 
  while (getline(ss, temp, delimiter)) {
    answer.push_back(temp);
  }
 
  return answer;
}

void toPairNumber(vector<string> &lines) {
  for(auto element : lines) {
    vector<string> temp = split(element, ' ');
    int hour, minute, second, milliSecond;

    string diffString = temp[2].substr(0, temp[2].size() - 1);
    vector<string> diffV = split(diffString, '.');
    int diff = stoi(diffV[0]) * 1e3 - 1;

    if(diffV.size() > 1) {
      while(diffV[1].size() < 3) {
        diffV[1].append("0");
      }

      diff += stoi(diffV[1]);
    }

    temp = split(temp[1], ':');

    hour = stoi(temp[0]) * 1e3 * 60 * 60;
    minute = stoi(temp[1]) * 1e3 * 60;

    temp = split(temp[2], '.');
    second = stoi(temp[0]) * 1e3;
    milliSecond = stoi(temp[1]);

    int endTime = hour + minute + second + milliSecond;

    v.push_back({endTime - diff, endTime});
  }
}

int solution(vector<string> lines) {
  int answer = 0;

  toPairNumber(lines);

  for(int i = 0; i < v.size(); i++) {
    int curEnd = v[i].second;
    int cnt = 0;
    for(int j = i; j < v.size(); j++) {
      if(v[j].first - 1000 < curEnd) {
        cnt++;
      }
    }

    answer = max(answer, cnt);
  }

  return answer;
}