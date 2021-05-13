#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool check[205];
int ans;

void bfs(int s, vector<vector<int>> &computers) {
    queue<int> q;
    q.push(s);

    while (q.size()) {
        int f = q.front();
        check[f] = true;
        q.pop();
        for (int i = 0; i < computers.size(); i++) {
            if (!check[i] && computers[f][i]) {
                q.push(i);
            }
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            ans++;
            bfs(i, computers);
        }
    }
    answer = ans;

    return answer;
}

int main() {
    vector<vector<int>> computers = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
    cout << solution(3, computers);

    return 0;
}