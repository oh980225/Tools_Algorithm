#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int dPos[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int n, m, ans;
int board[8][8];
int temp[8][8];

void func() {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 2) {
                q.push(pair<int, int>(i, j));
            }
        }
    }

    while (q.size()) {
        auto element = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dY = element.first + dPos[i][0];
            int dX = element.second + dPos[i][1];
            if (0 <= dY && dY < 8 && 0 <= dX && dX < 8 && temp[dY][dX] == 0) {
                temp[dY][dX] = 2;
                q.push(pair<int, int>(dY, dX));
            }
        }
    }

    int num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                num++;
            }
        }
    }

    ans = max(ans, num);
}

void makeWall(int cnt) {
    if (cnt == 3) {
        func();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                makeWall(cnt + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    makeWall(0);
        
    cout << ans;
   
    return 0;
}
