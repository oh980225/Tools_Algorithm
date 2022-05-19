#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < signs.size(); i++) {
      int curNum = absolutes[i];

      if(!signs[i]) {
        curNum *= -1;
      }

      answer += curNum;
    }
    
    return answer;
}