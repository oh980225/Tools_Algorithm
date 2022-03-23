#include <bits/stdc++.h>

using namespace std;

// key(맞힌 갯수), value(순위)
map<int, int> ranks;

void initRank() {
    ranks.insert({6, 1});
    ranks.insert({5, 2});
    ranks.insert({4, 3});
    ranks.insert({3, 4});
    ranks.insert({2, 5});
    ranks.insert({1, 6});
    ranks.insert({0, 6});
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    initRank();
    vector<int> answer;
    int minNum = 0;
    int maxNum = 0;
    
    for(int i = 0; i < 6; i++) {
        if(lottos[i] == 0) {
            maxNum++;
            continue;
        }
        for(int j = 0; j < 6; j++) {
            if(lottos[i] == win_nums[j]) {
                minNum++;
                maxNum++;
            }
        }
    }
    
    answer.push_back(ranks[maxNum]);
    answer.push_back(ranks[minNum]);
    
    return answer;
}