#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  int remain;
  while(n) {
    remain = n % 3;
    n /= 3;
    if(!remain) {
      answer = "4" + answer;
      n--;
      continue;
    }

    if(remain == 1) {
      answer = "1" + answer;
      continue;
    }

    if(remain == 2) {
      answer = "2" + answer;
      continue;
    }
  }
  
  return answer;
}