#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long l = 1;
    long long r = (long long) n * times[times.size() - 1];
    long long answer = r;

    while (l <= r) {
        long long mid = (l + r) / 2 + 1;
        long long temp = 0;

        for (auto time : times) {
            temp += mid / time;
        }
        if (temp < n) {
            l = mid + 1;
        }
        else {
            if (mid < answer)
                answer = mid;
            r = mid - 1;
        }
    }

    return answer;
}

int main() {
    vector<int> times;
    times.push_back(7);
    times.push_back(10);
    printf("ans : %lld", solution(6, times));

    return 0;
}