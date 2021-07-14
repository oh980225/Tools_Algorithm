#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int x = routes[0][1];

    for (auto element : routes) {
        if (x < element[0]) {
            answer++;
            x = element[1];
        }
        else {
            if (x > element[1])
                x = element[1];
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> routes;
    vector<int> car1;
    car1.push_back(-20);
    car1.push_back(15);
    vector<int> car2;
    car2.push_back(-14);
    car2.push_back(-5);
    vector<int> car3;
    car3.push_back(-18);
    car3.push_back(-13);
    vector<int> car4;
    car4.push_back(-5);
    car4.push_back(-3);

    routes.push_back(car1);
    routes.push_back(car2);
    routes.push_back(car3);
    routes.push_back(car4);

    printf("%d", solution(routes));

    return 0;
}