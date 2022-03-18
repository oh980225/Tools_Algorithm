#include <bits/stdc++.h>

using namespace std;

int dY[] = {-1, 0, 1, 0};
int dX[] = {0, 1, 0, -1};

vector<string> matrix;
bool chk[501][501][4];
int N, M;

int changeDir(int y, int x, int cur) {
    if(matrix[y][x] == 'S') {
        return cur;
    }
    
    if(matrix[y][x] == 'L') {
        cur -= 1;
        if(cur < 0) {
            return 3;
        }
        return cur;
    }
    
    if(matrix[y][x] == 'R') {
        cur += 1;
        if(3 < cur) {
            return 0;
        }
        return cur;
    }
    
    return -1;
}

int dfs(int y, int x, int dir, int len) {
    if(chk[y][x][dir]) {
        return len;
    }
    
    chk[y][x][dir] = true;
    int newDir = changeDir(y, x, dir);
    
    int newY = y + dY[newDir];
    int newX = x + dX[newDir];
    if(newY < 0) {
        newY = N - 1;
    }
    if(newX < 0) {
        newX = M - 1;
    }
    if(newY == N) {
        newY = 0;
    }
    if(newX == M) {
        newX = 0;
    }
    
    return dfs(newY, newX, newDir, len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    matrix = grid;
    N = matrix.size();
    M = matrix[0].size();
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
           for(int k = 0; k < 4; k++) {
               int result = dfs(i, j, k, 0);
               if(result != 0) {
                   answer.push_back(result);
               }
           } 
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}