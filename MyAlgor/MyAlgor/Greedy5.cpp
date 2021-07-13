#include <string>
#include <vector>
#include <queue>

using namespace std;

struct EDGE {
    int to, w;
};

vector<EDGE> adj[105];
bool chk[105];

bool operator < (EDGE e1, EDGE e2) {
    return e1.w > e2.w;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (auto element : costs) {
        adj[element[0]].push_back({ element[1], element[2] });
        adj[element[1]].push_back({ element[0], element[2] });
    }

    priority_queue<EDGE> pq;
    chk[0] = 1;
    for (int i = 0; i < adj[0].size(); i++) 
        pq.push(adj[0][i]);

    while (pq.size()) {
        auto curTo = pq.top().to;
        auto curW = pq.top().w;
        pq.pop();

        if (chk[curTo])
            continue;
        chk[curTo] = 1;
        answer += curW;

        for (int i = 0; i < adj[curTo].size(); i++) {
            if (!chk[adj[curTo][i].to])
                pq.push(adj[curTo][i]);
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> costs;
    vector<int> c1;
    c1.push_back(0);
    c1.push_back(1);
    c1.push_back(1);

    vector<int> c2;
    c2.push_back(0);
    c2.push_back(2);
    c2.push_back(2);

    vector<int> c3;
    c3.push_back(1);
    c3.push_back(2);
    c3.push_back(5);

    vector<int> c4;
    c4.push_back(1);
    c4.push_back(3);
    c4.push_back(1);

    vector<int> c5;
    c5.push_back(2);
    c5.push_back(3);
    c5.push_back(8);

    costs.push_back(c1);
    costs.push_back(c2);
    costs.push_back(c3);
    costs.push_back(c4);
    costs.push_back(c5);

    int ans = solution(4, costs);

    printf("%d", ans);

    return 0;
}