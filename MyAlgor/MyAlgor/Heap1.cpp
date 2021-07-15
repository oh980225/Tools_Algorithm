#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;

    for (auto element : scoville) 
        pq.push(-1 * element);

    while (pq.size()) {
        int curF = pq.top();
        pq.pop();
        if ((-1) * curF >= K) {
            return answer;
        }
        if (pq.size()) {
            int curS = pq.top();
            pq.pop();
            answer++;
            pq.push(curF + 2 * curS);
        }
    }

    return -1;
}

int main() {
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    printf("%d", solution(scoville, 7));

    return 0;
}