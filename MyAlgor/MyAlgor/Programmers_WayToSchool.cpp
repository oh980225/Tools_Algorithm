#include <string>
#include <vector>

using namespace std;

int map[101][101];
const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    map[1][1] = 1;
    for(auto pos : puddles) {
        map[pos[1]][pos[0]] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // 집인 경우
            if(i == 1 && j == 1) {
                continue;
            }
            
            // 잠긴 경우
            if(map[i][j] == -1) {
                continue;
            }
            
            // 그 외 경우
            int fromUp = map[i - 1][j];
            if(fromUp == -1) {
                fromUp = 0;
            }
            
            int fromLeft = map[i][j - 1];
            if(fromLeft == -1) {
                fromLeft = 0;
            }
            
            map[i][j] = (fromUp%MOD + fromLeft%MOD)%MOD;
        }
    }
    
    return map[n][m];
}