#include <bits/stdc++.h>

using namespace std;

int memo[1000005];

int solution(vector<int> money) {
    int idx = 2;
    int ans = 0;
    
    // 첫 번째 집을 무조건 터는 경우의 수 -> 마지막집 못텀
    for(auto element : money) {
        if(idx == money.size() + 1){
            continue;
        }
        memo[idx] = max(memo[idx - 1], memo[idx - 2] + element);
        idx++;
    }
    ans = max(ans, memo[money.size()]);
    
    memset(memo, 0, sizeof(memo));
    idx = 2;
    // 첫 집 안 터는 경우의 수
    for(auto element : money) {
        if(idx == 2){
            idx++;
            continue;
        }
        memo[idx] = max(memo[idx - 1], memo[idx - 2] + element);
        idx++;
    }
    ans = max(ans, memo[money.size() + 1]);
    
    return ans;
}