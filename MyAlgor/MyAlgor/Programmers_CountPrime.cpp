#include <bits/stdc++.h>

using namespace std;

vector<string> splitZero(string str) {
  vector<string> result;
  string temp = "";

  for(int i = 0; i < str.size(); i++) {
    if(str[i] == '0') {
      if(temp != "") {
        result.push_back(temp);
        temp = "";
      }
      continue;
    }
    temp += str[i];
  }

  if(temp != "") {
    result.push_back(temp);
  }

  return result;
}



string convert(int n, int k) {
  string result;

  while(n > 0) {
    result.push_back((n % k) + '0');

    n /= k;
  }

  reverse(result.begin(), result.end());

  return result;
}

bool isPrime(long long num) {
  if(num < 2) {
    return false;
  }

  for(long long i = 2; i * i <= num; i++) {
    if(num % i == 0) {
      return false;
    }
  }

  return true;
}

int solution(int n, int k) {
  int answer = 0;
  string converted = convert(n, k);
  vector<string> splitedNumber = splitZero(converted);

  for(auto number : splitedNumber) {
    if(isPrime(stoll(number))) {
      answer++;
    }
  }

  return answer;
}