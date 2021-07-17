#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    for (auto str : operations) {
        if (str[0] == 'I') {
            int num = stoi(str.substr(2));
            v.push_back(num);
        }
        if (str[0] == 'D') {
            if (v.size() == 0)
                continue;
            sort(v.begin(), v.end());
            if (str[2] == '1')
                v.erase(v.begin() + v.size() - 1);
            else
                v.erase(v.begin());
        }
    }

    sort(v.begin(), v.end());

    if (v.size() == 0)
        answer = { 0, 0 };
    else
        answer = { v[v.size() - 1], v[0] };

    return answer;
}

int main() {
    vector<string> operations;
    operations.push_back("I 7");
    operations.push_back("I 15");
    operations.push_back("D 1");
    operations.push_back("D 1");
    operations.push_back("D 1");
    operations.push_back("I -5");

    vector<int> ans = solution(operations);
    for (auto element : ans) {
        cout << element << endl;
    }
    return 0;
}