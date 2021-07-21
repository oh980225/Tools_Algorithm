#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct EDGE {
    int to, w;
};

vector<EDGE> adj[20005];

bool operator < (EDGE e1, EDGE e2) {
    return e1.w > e2.w;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = -1;
    vector<int> ans(n);
    vector<bool> chk(n);
    fill(ans.begin(), ans.end(), 1e9);
    for (auto e : edge) {
        adj[e[0] - 1].push_back({ e[1] - 1, 1 });
        adj[e[1] - 1].push_back({ e[0] - 1, 1 });
    }

    priority_queue<EDGE> pq;
    pq.push({0, 0});
    ans[0] = 0;
    while (pq.size()) {
        auto curTo = pq.top().to;
        auto curW = pq.top().w;
        pq.pop();
        if (chk[curTo])
            continue;
        chk[curTo] = 1;
        for (auto element : adj[curTo]) {
            if (ans[element.to] > curW + element.w) {
                ans[element.to] = curW + element.w;
                if (curW + element.w > max)
                    max = curW + element.w;
                pq.push({ element.to, curW + element.w });
            }
        }
    }

    for (auto element : ans) {
        if (element == max)
            answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> edge;
    vector<int> e1;
    e1.push_back(3);
    e1.push_back(6);
    vector<int> e2;
    e2.push_back(4);
    e2.push_back(3);
    vector<int> e3;
    e3.push_back(3);
    e3.push_back(2);
    vector<int> e4;
    e4.push_back(1);
    e4.push_back(3);
    vector<int> e5;
    e5.push_back(1);
    e5.push_back(2);
    vector<int> e6;
    e6.push_back(2);
    e6.push_back(4);
    vector<int> e7;
    e7.push_back(5);
    e7.push_back(2);

    edge.push_back(e1);
    edge.push_back(e2);
    edge.push_back(e3);
    edge.push_back(e4);
    edge.push_back(e5);
    edge.push_back(e6);
    edge.push_back(e7);

    printf("%d\n", solution(6, edge));

    return 0;
}