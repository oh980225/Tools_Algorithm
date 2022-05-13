#include <bits/stdc++.h>

using namespace std;

map<string, string> userNickName;

vector<string> split(string str, char delimiter) {
  vector<string> result;
  string temp;
  stringstream ss(str);

  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

void changeNickName(vector<string> command) {
  if(command.size() > 2) {
    userNickName[command[1]] = command[2];
  }
}

vector<string> solution(vector<string> record) {
  vector<string> answer;

  for(auto command : record) {
    auto splitedCommand = split(command, ' ');
    changeNickName(splitedCommand);
  }

  for(auto command : record) {
    auto splitedCommand = split(command, ' ');

    if(splitedCommand[0] == "Enter") {
      answer.push_back(userNickName[splitedCommand[1]] + "님이 들어왔습니다.");
      continue;
    }

    if(splitedCommand[0] == "Leave") {
      answer.push_back(userNickName[splitedCommand[1]] + "님이 나갔습니다.");
      continue;
    }
  }

  return answer;
}