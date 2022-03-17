#include <bits/stdc++.h>

using namespace std;

bool chk[5];
int dY[] = {0, 0, -1, 1};
int dX[] = {-1, 1, 0, 0};
vector<vector<string>> myPlace;
bool visited[5][5];

void dfs(int idx, int y, int x, int cur) {
    if(cur == 1 || cur == 2) {
        if(myPlace[idx][y][x] == 'P') {
            chk[idx] = true;
        }
    }
    if(cur == 2) {
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int newY = y + dY[i];
        int newX = x + dX[i];
        if(0 <= newY && newY < 5 && 0 <= newX && newX < 5 && !visited[newY][newX] && myPlace[idx][newY][newX] != 'X') {
            visited[newY][newX] = true;
            dfs(idx, newY, newX, cur + 1);
            visited[newY][newX] = false;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    myPlace = places;
    int idx = 0;
    for(auto place : places) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(chk[idx]) {
                    break;
                }
                if(place[i][j] == 'P') {
                    visited[i][j] = true;
                    dfs(idx, i, j, 0);
                    visited[i][j] = false;
                }
            }
            if(chk[idx]) {
                break;
            }
        }
        idx++;
    }
    
    for(int i = 0;  i < 5; i++) {
        if(!chk[i]) {
            answer.push_back(1);
            continue;
        }
        answer.push_back(0);
    }
    
    return answer;
}