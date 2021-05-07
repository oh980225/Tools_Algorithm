#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, bool> m;

bool check(string number) {
    for (int i = 0; i < number.size(); i++) {
        if (m[number.substr(0, i + 1)]) {
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (auto element : phone_book) {
        if (!check(element)) {
            answer = false;
            break;
        }
        m[element] = true;
    }

    return answer;
}

int main() {
    vector<string> v;
    v.push_back("12");
    v.push_back("123");
    v.push_back("567");
    v.push_back("1235");
    v.push_back("88");

    cout << solution(v);

    return 0;
}