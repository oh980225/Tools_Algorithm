#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int l = 0;
    int r = people.size() - 1;
    while (l <= r) {
        if (limit >= (people[l] + people[r])) {
            l++;
            r--;
        }
        else {
            r--;
        }
        answer++;
    }
    return answer;
}

int main() {
    vector<int> people;
    people.push_back(70);
    //people.push_back(50);
    people.push_back(80);
    people.push_back(50);
    int ans = solution(people, 100);

    printf("%d", ans);
    return 0;
}