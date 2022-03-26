#include <bits/stdc++.h>

using namespace std;

string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
map<string, string> m;

void init() {
  m.insert({numbers[0], "0"});
  m.insert({numbers[1], "1"});
  m.insert({numbers[2], "2"});
  m.insert({numbers[3], "3"});
  m.insert({numbers[4], "4"});
  m.insert({numbers[5], "5"});
  m.insert({numbers[6], "6"});
  m.insert({numbers[7], "7"});
  m.insert({numbers[8], "8"});
  m.insert({numbers[9], "9"});
}

pair<string, int> findNumber(string s) {
  for(auto element : numbers) {
    if(s.find(element) != string::npos) {
      return {element, s.find(element)};
    }
  }

  return {"", -1};
}

int solution(string s) {
    init();

    int index = 0;
    while(true) {
      auto findResult = findNumber(s);
      
      if(findResult.second == -1) {
        break;
      }

      s.replace(findResult.second, findResult.first.size(), m[findResult.first]);
    }

    int answer = stoi(s);

    return answer;
}