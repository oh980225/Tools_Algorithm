#include <string>
#include <vector>

using namespace std;

int one[5] = { 1, 2, 3, 4, 5 };
int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int three[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int oneCount(vector<int> answers) {
    int idx = 0;
    int cnt = 0;
    for (auto element : answers) {
        if (idx >= 5) {
            idx = 0;
        }
        if (element == one[idx++]) {
            cnt++;
        }
    }
    return cnt;
}

int twoCount(vector<int> answers) {
    int idx = 0;
    int cnt = 0;
    for (auto element : answers) {
        if (idx >= 8) {
            idx = 0;
        }
        if (element == two[idx++]) {
            cnt++;
        }
    }
    return cnt;
}

int threeCount(vector<int> answers) {
    int idx = 0;
    int cnt = 0;
    for (auto element : answers) {
        if (idx >= 10) {
            idx = 0;
        }
        if (element == three[idx++]) {
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int maxCount = oneCount(answers);
    int tempCount = twoCount(answers);

    if (maxCount == tempCount) {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if (maxCount < tempCount) {
        maxCount = tempCount;
        answer.push_back(2);
    }
    else {
        answer.push_back(1);
    }

    tempCount = threeCount(answers);
    if (maxCount == tempCount) {
        answer.push_back(3);
    }
    else if (maxCount < tempCount) {
        answer.clear();
        answer.push_back(3);
    }

    return answer;
}

int main() {
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);
    test.push_back(2);
    vector<int> answer = solution(test);
    for (auto element : answer) {
        printf("%d\n", element);
    }
    return 0;
}
