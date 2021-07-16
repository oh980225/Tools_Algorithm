#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

// SJF 알고리즘 사용
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    vector<int> result;

    sort(jobs.begin(), jobs.end(), compare);

    while (jobs.size()) {
        int idx = 0;
        bool flag = false;
        for (auto job : jobs) {
            if (job[0] <= curTime) {
                curTime += job[1];
                result.push_back(curTime - job[0]);
                flag = true;

                break;
            }
            idx++;
        }

        if (flag) {
            jobs.erase(jobs.begin() + idx);
            continue;
        }

        curTime++;
    }

    int sum = 0;

    for (auto element : result) 
        sum += element;

    answer = sum / result.size();

    return answer;
}
