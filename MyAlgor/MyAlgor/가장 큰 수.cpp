#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    for (auto el : numbers) {
        v.push_back(to_string(el));
    }
    sort(v.begin(), v.end(), compare);
    for (auto el : v) {
        answer += el;
    }
    if (answer[0] == '0') {
        return "0";
    }
    return answer;
}

int main() {
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(2);
    numbers.push_back(10);

    string answer = solution(numbers);
    cout << answer << endl;
    return 0;
}