#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[9];

void init(int N) {
    for (int i = 1; i <= 8; i++) {
        int num = 0;
        for (int j = 1; j < pow(10, i); j*=10) {
            num += N * j;
        }
        v[i].push_back(num);
    }
}

int solution(int N, int number) {
    init(N);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= i; j++) {
            for (auto f : v[j]) {
                for (auto s : v[i - j]) {
                    v[i].push_back(f + s);
                    v[i].push_back(f - s);
                    v[i].push_back(f * s);
                    if (s != 0)
                        v[i].push_back(f / s);
                }
            }
        }
        auto it = find(v[i].begin(), v[i].end(), number);
        if (it != v[i].end()) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, number;
    scanf_s("%d %d", &n, &number);
    printf("%d", solution(n, number));

    return 0;
}