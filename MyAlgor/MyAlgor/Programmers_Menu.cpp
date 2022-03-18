#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto element : course) {
        vector<int> v;
        vector<int> temp;
        for(int i = 0; i < 26 - element; i++) {
            v.push_back(0);
            temp.push_back(0);
        }
        for(int i = 0; i < element; i++) {
            v.push_back(1);
            temp.push_back(1);
        }
        
        // maxTotal을 우선 구해야한다!
        int maxTotal = 0;
        do {
            int total = 0;
            for(auto order : orders) {
                int cnt = 0;
                for(int j = 0; j < order.size(); j++) {
                    char alph = order[j];
                    if(temp[alph - 'A']) {
                        cnt++;
                    }
                }
                
                if(cnt == element) {
                    total++;
                }
            }
            
            maxTotal = max(total, maxTotal);
        } while(next_permutation(temp.begin(), temp.end()));
        
        if(maxTotal < 2) {
            continue;
        }
        
        do {
            int total = 0;
            for(auto order : orders) {
                int cnt = 0;
                for(int j = 0; j < order.size(); j++) {
                    char alph = order[j];
                    if(v[alph - 'A']) {
                        cnt++;
                    }
                }
                
                if(cnt == element) {
                    total++;
                }
            }
            
            if(total == maxTotal) {
                string str = "";
                for(int i = 0; i < 26; i++) {
                    if(v[i]) {
                        str.append(1, i + 'A');
                    }
                }
                answer.push_back(str);
            }
        } while(next_permutation(v.begin(), v.end()));
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}