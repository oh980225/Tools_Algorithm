#include <bits/stdc++.h>

using namespace std;

map<string, int> totalFeeMap;
int defaultTime;
int defaultFee;
int unitTime;
int unitFee;
const int MAX_TIME = 23 * 60 + 59;

struct Status {
  int curTime;
  int spendTime;
  bool isIn;
};

map<string, Status> statusMap;

vector<string> split(string str, char delimiter) {
  stringstream ss(str);
  string temp;
  vector<string> result;

  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

int getTime(string time) {
  auto minAndHour = split(time, ':');
  return stoi(minAndHour[0]) * 60 + stoi(minAndHour[1]);
}

int getFee(int spendTime) {
  if(spendTime <= defaultTime) {
    return defaultFee;
  }

  spendTime -= defaultTime;
  int additionalFee = ceil(((double) spendTime / (double) unitTime)) * unitFee;

  return defaultFee + additionalFee;
}

void calculateFee() {
  for(auto status : statusMap) {
    if(status.second.isIn) {
      int pre = status.second.curTime;
      status.second.spendTime += (MAX_TIME - pre);
    }

    totalFeeMap[status.first] += getFee(status.second.spendTime);
  }
}

void accumulateTimePerCar(vector<string>& records) {
  for(auto record : records) {
    vector<string> splitedRecord = split(record, ' ');
    int time = getTime(splitedRecord[0]);
    string carNumber = splitedRecord[1];
    string inOrOut = splitedRecord[2];
    auto curState = statusMap[carNumber];

    if(inOrOut == "IN") {
      statusMap[carNumber] = {time, curState.spendTime, true};
      continue;
    }

    statusMap[carNumber] = {time, curState.spendTime + time - curState.curTime, false};
  }
}

vector<int> solution(vector<int> fees, vector<string> records) {
  vector<int> answer;
  defaultTime = fees[0];
  defaultFee = fees[1];
  unitTime = fees[2];
  unitFee = fees[3];

  accumulateTimePerCar(records);

  calculateFee();

  for(auto element : totalFeeMap) {
    answer.push_back(element.second);
  }

  return answer;
}