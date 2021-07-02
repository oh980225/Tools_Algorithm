#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size() - k;
    int idx = 0;
    for (int i = 0; i < size; i++) {
        char maxNum = number[idx];
        for (int j = idx; j <= k + i; j++) {
            if (number[j] > maxNum) {
                maxNum = number[j];
                idx = j;
            }
        }
        answer += maxNum;
        idx += 1;
    }
    return answer;
}

int main() {
    string ans = solution("4177252841", 4);
    cout << ans;
    return 0;
}