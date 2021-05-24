#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> check;

bool compare(vector<string> a, vector<string> b) {
    return a[1]  < b[1];
}

bool dfs(vector<vector<string>> &tickets, vector<string> &answer, int cnt) {
    if (tickets.size() == cnt) {
        return true;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == answer[answer.size() - 1] && !check[i]) {
            answer.push_back(tickets[i][1]);
            check[i] = 1;
            bool chk = dfs(tickets, answer, cnt + 1);
            if (chk)
                return true;
            answer.pop_back();
            check[i] = 0;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    check.resize(tickets.size());
    string first = "ICN";

    sort(tickets.begin(), tickets.end(), compare);
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == first) {
            answer.push_back(first);
            answer.push_back(tickets[i][1]);
            check[i] = 1;
            bool chk = dfs(tickets, answer, 1);
            if (chk)
                break;
        }
        int s = tickets.size();
        check = vector<int>(s, 0);
        answer.clear();
    }
        
    return answer;
}

int main() {
    vector<vector<string>> str = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };

    vector<string> ans = solution(str);

    for (auto element : ans) {
        cout << element << endl;
    }

    return 0;
}