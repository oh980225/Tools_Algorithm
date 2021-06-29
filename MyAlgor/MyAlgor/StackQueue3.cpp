#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> truck;
    queue<int> bridge;
    vector<int> result;

    for (int i = 0; i < bridge_length; i++)
        bridge.push(0);

    for (auto el : truck_weights)
        truck.push(el);

    while (1) {
        answer++;
        int bF = bridge.front();
        bridge.pop();
        if (bF != 0) {
            result.push_back(bF);
            if (result.size() >= truck_weights.size()) {
                break;
            }
        }
        sum -= bF;
        if (truck.size() && weight >= sum + truck.front()) {
            sum += truck.front();
            bridge.push(truck.front());
            truck.pop();
        }
        else { 
            bridge.push(0); 
        }
    }

    return answer;
}

int main() {
    vector<int> truck_weights;
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);

    int ans = solution(100, 100, truck_weights);
    
    printf("%d", ans);

    return 0;
}