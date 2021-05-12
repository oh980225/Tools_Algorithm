//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//map<string, vector<pair<int, int>>> m;
//
//bool compare(pair<string, int> a, pair<string, int> b) {
//    return a.second > b.second;
//}
//
//bool compare2(pair<int, int> a, pair<int, int>b) {
//    return a.first > b.first;
//}
//
//vector<int> solution(vector<string> genres, vector<int> plays) {
//    vector<int> answer;
//
//    for (int i = 0; i < genres.size(); i++) {
//        m[genres[i]].push_back(make_pair(plays[i], i));
//    }
//
//    map<string, vector<pair<int, int>>>::iterator it;
//    vector<pair<string, int>> temp;
//    for (it = m.begin(); it != m.end(); it++) {
//        int total = 0;
//        for (auto element : it->second) {
//            total += element.first;
//        }
//        temp.push_back(make_pair(it->first, total));
//    }
//
//    sort(temp.begin(), temp.end(), compare);
//
//    for (auto element : temp) {
//        sort(m[element.first].begin(), m[element.first].end(), compare2);
//        answer.push_back(m[element.first][0].second);
//        if (m[element.first].size() > 1) {
//            answer.push_back(m[element.first][1].second);
//        }
//    }
//
//    return answer;
//}
//
//int main() {
//    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
//    vector<int> plays = { 500, 600, 150, 800, 2500 };
//    
//    vector<int> answer = solution(genres, plays);
//
//    for (auto element : answer) {
//        cout << element << ", ";
//    }
//    
//    return 0;
//}