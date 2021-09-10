#include <string>
#include <vector>

using namespace std;

int memo[505][505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    memo[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                memo[i][j] = memo[i - 1][j] + triangle[i][j];
            }
            if (i == j) {
                memo[i][j] = memo[i - 1][j - 1] + triangle[i][j];
            }
            else {
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - 1]) + triangle[i][j];
            }
            answer = max(answer, memo[i][j]);
        }
    }

    return answer;
}
