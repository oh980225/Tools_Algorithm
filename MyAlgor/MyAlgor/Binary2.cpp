#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int l = 0;
    int r = distance;

    while (l <= r) {
        int cnt = 0;
        int mid = (l + r) / 2;
        int pre = 0;
        for (auto rock : rocks) {
            if (rock - pre < mid) {
                cnt++;
                continue;
            }
            pre = rock;
        }
        if (distance - pre < mid) 
            cnt++;
        if (cnt <= n) {
            answer = mid;
            l = mid + 1;
            continue;
        }
        r = mid - 1;
    }

    return answer;
}

int main() {
    vector<int> rocks;
    rocks.push_back(2);
    rocks.push_back(14);
    rocks.push_back(11);
    rocks.push_back(21);
    rocks.push_back(17);
    
    printf("%d\n", solution(25, rocks, 2));

    return 0;
}