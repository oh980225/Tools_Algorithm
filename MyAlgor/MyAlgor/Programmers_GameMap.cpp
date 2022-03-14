#include<bits/stdc++.h>

using namespace std;

bool chk[101][101];
int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{0, 0}, 1});
    chk[0][0] = 1;
    while(q.size()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.first.first == maps.size() - 1 && cur.first.second == maps[0].size() - 1) {
            return cur.second;
        }
        
        for(int i = 0; i < 4; i++) {
            int newY = cur.first.first + dY[i];
            int newX = cur.first.second + dX[i];
            if(0 <= newY && newY <= maps.size() - 1 && 0 <= newX && newX <= maps[0].size() - 1 && maps[newY][newX] && !chk[newY][newX]) {
                chk[newY][newX] = 1;
                q.push({{newY, newX}, cur.second + 1});
            }
        }
    }
    
    return -1;
}