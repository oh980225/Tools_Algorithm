#include <bits/stdc++.h>

using namespace std;

map<string, int> gemMap;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> gemSet(gems.begin(), gems.end());
    int l = 0;
    int r = 0;

    for(auto gem : gems) {
        gemMap[gem]++;
        if(gemMap.size() == gemSet.size()) 
            break;
        r++;
    }

    int min = r - l;
    answer[0] = l + 1;
    answer[1] = r + 1;

    while(r < gems.size()) {
        string gem = gems[l];
        gemMap[gem]--;
        l++;

        if(!gemMap[gem]) {
            r++;
            for(; r < gems.size(); r++) {
                gemMap[gems[r]]++;
                if(gem == gems[r])
                    break;
            }
            if(r == gems.size())
                break;
        }

        if(min > r - l) {
            answer[0] = l + 1;
            answer[1] = r + 1;
            min = r - l;
        }
    }

    return answer;
}