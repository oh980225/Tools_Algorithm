#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string>> reportHistory;
unordered_map<string, int> cumulativeNumber;

vector<string> split(string str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string temp;

  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

void recordHistory(vector<string>& report) {
  for(auto content : report) {
    vector<string> history = split(content, ' ');
    string reporter = history[0];
    string reported = history[1];

    int preSize = reportHistory[reporter].size();
    reportHistory[reporter].insert(reported);
    int curSize = reportHistory[reporter].size();

    if(preSize != curSize) {
      cumulativeNumber[reported]++;
    }
  }
}

void checkStopped(vector<string>& id_list, int standard, vector<int>& answer) {
  for(int i = 0; i < id_list.size(); i++) {
    int cnt = 0;
    auto historySet = reportHistory[id_list[i]];

    for(auto reported : historySet) {
      if(cumulativeNumber[reported] >= standard) {
        cnt++;
      }
    }

    answer.push_back(cnt);
  }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;

  recordHistory(report);

  checkStopped(id_list, k, answer);

  return answer;
}