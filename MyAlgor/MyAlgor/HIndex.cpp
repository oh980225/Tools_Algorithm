#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), compare);

    int maxNum = citations[0];

    while (maxNum > 0) {
        int more = 0;
        for (auto el : citations) {
            if (maxNum <= el) {
                more++;
            }
            else 
                break;
        }
        if (more >= maxNum) {
            answer = maxNum;
            break;
        }
        maxNum--;
    }
    return answer;
}

int main() {
    vector<int> test;
    test.push_back(3);
    test.push_back(0);
    test.push_back(6);
    test.push_back(1);
    test.push_back(5);

    cout << solution(test) << "\n";

    return 0;
}