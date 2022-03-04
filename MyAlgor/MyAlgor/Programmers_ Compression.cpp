#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i = 1; i <= s.size() / 2; i++) {
        string temp1, temp2;
        int cnt = 1;
        temp1 = s.substr(0, i);
        
        for(int j=i; j < s.size(); j+=i) {
            if(temp1 == s.substr(j, i)) {
                cnt++;
                continue;
            }
            
            if(cnt > 1) {
                temp2 += to_string(cnt);
            }
            temp2 += temp1;
            temp1 = s.substr(j, i);
            cnt = 1;
        }
        
        if(cnt > 1) {
            temp2 += to_string(cnt);
        }
        temp2 += temp1;
        cnt = 1;
        
        answer = min((int) temp2.size(), answer);
    }
    
    return answer;
}