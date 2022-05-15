#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char delimiter) {
  string temp;
  vector<string> result;
  stringstream ss(str);

  while(getline(ss, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

int timeToValue(string timeStr) {
  auto splitedTime = split(timeStr, ':');
  int hour = stoi(splitedTime[0]);
  int min = stoi(splitedTime[1]);

  return hour * 60 + min;
}

string valueToTime(int value) {
  int hour = 0;
  hour = value / 60;
  int min = value - (hour * 60);

  string hourStr = to_string(hour);
  string minStr = to_string(min);

  if(hourStr.size() < 2) {
    hourStr = "0" + hourStr;
  }

  if(minStr.size() < 2) {
    minStr = "0" + minStr;
  }

  return hourStr + ":" + minStr;
}

string solution(int n, int t, int m, vector<string> timetable) {
  priority_queue<int, vector<int>, greater<int>> pq;

  int firstBusTime = timeToValue("09:00");
  int curBusTime = firstBusTime;
  int endBusTime = firstBusTime + t * (n - 1);

  for(auto time : timetable) {
    pq.push(timeToValue(time));
  }

  int cnt = 0;
  int preCnt = 0;
  int lastTime = 0;
  
  while(pq.size()) {
    auto first = pq.top();
    pq.pop();

    if(curBusTime > endBusTime) {
      break;
    }

    if(cnt == m || (first > curBusTime)) {
      preCnt = cnt;
      cnt = 0;
      curBusTime += t;
      pq.push(first);
      continue;
    }

    lastTime = first;
    cnt++;
  }


  if(cnt == m || ((curBusTime > endBusTime) && preCnt == m)) {
    lastTime--;
  } else {
    lastTime = endBusTime;
  }

  return valueToTime(lastTime);
}