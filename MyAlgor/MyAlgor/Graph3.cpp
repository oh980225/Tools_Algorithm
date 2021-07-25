#include <string>
#include <vector>
#include <map>

using namespace std;


pair<int, int> moveArr[8] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int solution(vector<int> arrows) {
    map<pair<int, int>, bool> v;
    map<pair<pair<int, int>, pair<int, int>>, bool> e;

    int answer = 0;
    int x = 0;
    int y = 0;
    v[{x, y}] = true;

    for (auto arrow : arrows) {
        for (int i = 0; i < 2; i++) {
            int newX = x + moveArr[arrow].first;
            int newY = y + moveArr[arrow].second;

            if (v[{newX, newY}] == true && e[{ {x, y}, { newX, newY }}] == false) {
                answer++;
                e[{ {x, y}, { newX, newY }}] = true;
                e[{ { newX, newY }, {x, y} }] = true;
                x = newX;
                y = newY;
                continue;
            }

            v[{newX, newY}] = true;
            e[{ {x, y}, { newX, newY }}] = true;
            e[{ { newX, newY }, { x, y } }] = true;
            x = newX;
            y = newY;
        }
    }

    return answer;
}

int main() {
    vector<int> arrows = { 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 };

    printf("%d", solution(arrows));
    return 0;
}