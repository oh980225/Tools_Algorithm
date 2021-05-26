#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto element : commands) {
        vector<int> temp(array.begin() + element[0] - 1, array.begin() + element[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[element[2] - 1]);
    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> command = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    vector<int> ans = solution(array, command);

    for (auto element : ans) {
        cout << element << endl;
    }
}