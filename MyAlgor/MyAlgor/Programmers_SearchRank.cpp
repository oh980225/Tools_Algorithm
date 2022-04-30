#include <bits/stdc++.h>

using namespace std;

map<string, vector<int>> scoresPerCondition;

vector<string> split(string str, char separator) {
  stringstream ss(str);
  string temp;
  vector<string> result;

  while(getline(ss, temp, separator)) {
    result.push_back(temp);
  }

  return result;
}

vector<string> getConditions(vector<string>& v, int r) {
  // r개의 조건은 상관 없을 때!
  vector<bool> comb = vector<bool>(r, 0);
  vector<string> result;

  for(int i = 0; i < 4 - r; i++) {
    comb.push_back(1);
  }

  do {
    string key = "";

    for(int i = 0; i < 4; i++) {
      if(comb[i]) {
        key += v[i];
        continue;
      }

      key += "-";
    }

    result.push_back(key);
  } while(next_permutation(comb.begin(), comb.end()));

  return result;
}

void recordInfo(vector<string>& info) {
  for(auto element : info) {
    vector<string> separated = split(element, ' ');
    int score = stoi(separated[4]);

    for(int i = 0; i <= 4; i++) {
      vector<string> keys = getConditions(separated, i);

      for(auto key : keys) {
        scoresPerCondition[key].push_back(score);
      }
    }
  }
}

void sortScoresPerCondition() {
  for(auto iter = scoresPerCondition.begin(); iter != scoresPerCondition.end(); iter++) {
    sort(iter->second.begin(), iter->second.end());
  }
}

void executeQuery(vector<int>& ans, vector<string>& query) {
  for(auto element : query) {
    vector<string> separated = split(element, ' ');
    int needScore = stoi(separated[separated.size() - 1]);

    string condition = "";
    for(int i = 0; i < separated.size() - 1; i++) {
      if(separated[i] == "and") {
        continue;
      }

      condition += separated[i];
    }

    auto scores = scoresPerCondition[condition];
    auto it = lower_bound(scores.begin(), scores.end(), needScore);

    ans.push_back(scores.size() - 1 - (it - scores.begin()) + 1);
  }
}

vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;

  recordInfo(info);

  sortScoresPerCondition();

  executeQuery(answer, query);

  return answer;
}