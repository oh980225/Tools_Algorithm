#include <bits/stdc++.h>

using namespace std;

const int HOUR_TO_SEC = 60 * 60;
const int MIN_TO_SEC = 60;

const int MAX_TIME_SEC = HOUR_TO_SEC * 99 + MIN_TO_SEC * 59 + 59;

int accumulateArr[MAX_TIME_SEC + 2];

vector<string> split(string str, char separator) {
  stringstream ss(str);
  string temp;
  vector<string> result;

  while(getline(ss, temp, separator)) {
    result.push_back(temp);
  }

  return result;
}

int getTimeValue(string time) {
  vector<string> separatedTime = split(time, ':');
 
  return HOUR_TO_SEC * stoi(separatedTime[0]) + MIN_TO_SEC * stoi(separatedTime[1]) + stoi(separatedTime[2]);
}

void recordLogs(vector<string>& logs) {
  for(auto log : logs) {
    vector<string> separatedLog = split(log, '-');
    string startTime = separatedLog[0];
    string endTime = separatedLog[1];

    int startTimeValue = getTimeValue(startTime);
    int endTimeValue = getTimeValue(endTime);

    accumulateArr[startTimeValue]++;
    accumulateArr[endTimeValue]--;
  }
}

void accumulate(int endTime) {
  for(int i = 1; i <= endTime; i++) {
    accumulateArr[i] += accumulateArr[i - 1];
  }
}

int goodStartTime(int playEnd, int advEnd) {
  long long maxTotal = 0;
  int startTime = 0;
  for(int i = 0; i < advEnd; i++) {
    maxTotal += accumulateArr[i];
  }

  long long preTotal = maxTotal;
  for(int i = 1; i + advEnd <= playEnd; i++) {
    long long curTotal = preTotal - accumulateArr[i - 1] + accumulateArr[i + advEnd - 1];
    preTotal = curTotal;
    
    if(maxTotal < curTotal) {
      maxTotal = curTotal;
      startTime = i;
    }
  }

  return startTime;
}

string convertStringTime(int timeValue) {
  string result = "";
  int hour = floor(timeValue / (60 * 60));
  timeValue -= (hour * 60 * 60);
  if(hour < 10) {
    result += "0";
  }
  result += to_string(hour);
  result += ":";

  int min = floor(timeValue / (60));
  timeValue -= (min * 60);
  if(min < 10) {
    result += "0";
  }
  result += to_string(min);
  result += ":";

  int sec = timeValue;
  if(sec < 10) {
    result += "0";
  }
  result += to_string(sec);

  return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
  recordLogs(logs);

  int playEndTime = getTimeValue(play_time);
  accumulate(playEndTime);

  int advEndTime = getTimeValue(adv_time);
  int result = goodStartTime(playEndTime, advEndTime);

  return convertStringTime(result);
}