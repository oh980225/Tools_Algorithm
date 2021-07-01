#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < prices.size(); i++) 
        q.push(prices[i]);
    int idx = 0;
    while (q.size()) {
        auto f = q.front();
        q.pop();
        int cnt = 0;
        for (int i = idx; i < (prices.size() - 1); i++) {
            if (prices[i] >= f)
                cnt++;
            else
                break;
        }
        answer.push_back(cnt);
        idx++;
    }
    return answer;
}

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    vector<int> result = solution(prices);
    for (auto el : result)
        printf("%d\n", el);
    return 0;
}