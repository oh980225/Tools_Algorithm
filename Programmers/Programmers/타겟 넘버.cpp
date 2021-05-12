#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
int t;
int ans;
bool check[22];

void dfs(int idx, int total) {
    if (total == t) {
        ans++;
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        if (!check[i]) {
            check[i] = true;
            v[i] *= (-1);
            dfs(i, total + 2 * v[i]);
            v[i] *= (-1);
            check[i] = false;
        }
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    v = numbers;
    t = target;
    int total = 0;

    for (auto number : numbers) {
        total += number;
    }

    dfs(0, total);
    answer = ans;

    return answer;
}

int main() {
    vector<int> numbers = { 1, 3, 5, 8, 1 };
    cout << solution(numbers, 2);
    return 0;
}