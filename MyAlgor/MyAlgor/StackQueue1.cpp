#include <string>
#include <vector>
#include <queue>

using namespace std;

struct JOB {
    int per;
    int up;
    int order;
};

// 기능 개발
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<JOB> q;
    for (int i = 0; i < progresses.size(); i++) {
        q.push({progresses[i], speeds[i], i});
    }
    int s = 0;
    int cnt = 0;
    bool flag = false;
    while (q.size()) {
        auto f = q.front();
        int curPer = f.per;
        int curOrder = f.order;
        int curUp = f.up;
        q.pop();
        if (curOrder <= s && curPer >= 100) {
            s++;
            cnt++;
            flag = true;
            continue;
        }
        else {
            if (flag) {
                answer.push_back(cnt);
                flag = false;
                cnt = 0;
            }
        }
        q.push({ curPer + curUp, curUp, curOrder });
    }
    answer.push_back(cnt);

    return answer;
}

int main() {
    vector<int> progresses;
    progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);
    vector<int> speeds;
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);

    vector<int> ans = solution(progresses, speeds);
    for (auto el : ans) {
        printf("%d\n", el);
    }
    return 0;
}