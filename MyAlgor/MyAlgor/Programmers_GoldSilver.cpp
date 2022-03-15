#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll r = 2 * 1e9 * 1e5 * 2;
    ll answer = r;
    ll l = 0;
    
    while(l <= r) {
        ll gold = 0;
        ll silver = 0;
        ll mix = 0;
        ll mid = (l + r) / 2;
        
        for(int i = 0; i < g.size(); i++) {
            ll curGold = (ll) g[i];
            ll curSilver = (ll) s[i];
            ll curW = (ll) w[i];
            ll curT = (ll) t[i];
            
            ll moveCnt = mid / curT;
            if(moveCnt % 2) {
                moveCnt /= 2;
                moveCnt++;
            } else {
                moveCnt /= 2;
            }
            
            gold += (curGold < moveCnt * curW) ? curGold : moveCnt * curW;
            silver += (curSilver < moveCnt * curW) ? curSilver : moveCnt * curW;
            mix += (curGold + curSilver < moveCnt * curW) ? curGold + curSilver : moveCnt * curW;
        }
        
        if(gold >= a && silver >= b && mix >= a + b) {
            r = mid - 1;
            answer = min(mid, answer);            
            continue;
        }
        l = mid + 1;
    }
    
    return answer;
}