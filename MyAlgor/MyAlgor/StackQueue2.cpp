#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (auto el : priorities) 
        pq.push(el);
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
    }

    int order = 0;

    while (q.size()) {
        auto pqT = pq.top();
        auto qF = q.front();
        q.pop();
        if (pqT == qF.second) {
            order++;
            if (qF.first == location) {
                answer = order;
                break;
            }
            pq.pop();
            continue;
        }
        q.push(qF);
    }
    return answer;
}

int main() {
    vector<int> priorities;
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);
    int ans = solution(priorities, 0);
    printf("%d", ans);
    return 0;
}