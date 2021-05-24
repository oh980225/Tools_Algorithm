//#include <string>
//#include <vector>
//#include <queue>
//#include <map>
//#include <iostream>
//
//using namespace std;
//
//int check[55];
//map<string, int> m;
//
//int bfs(string begin, string target, vector<string> &words) {
//    queue<string> q;
//    q.push(begin);
//    check[m[begin]] = 1;
//    while (q.size()) {
//        auto f = q.front();
//        q.pop();
//        if (f == target)
//            return check[m[target]];
//        for (int i = 0; i < words.size(); i++) {
//            int diff = 0;
//            for (int j = 0; j < words[i].size(); j++) 
//                if (f[j] != words[i][j])
//                    diff++;
//            if (!check[m[words[i]]] && diff < 2) {
//                check[m[words[i]]] = check[m[f]] + 1;
//                q.push(words[i]);
//            }
//        }
//    }
//    return 1;
//}
//
//int solution(string begin, string target, vector<string> words) {
//    int answer = 0;
//    auto it = find(words.begin(), words.end(), target);
//    if (it == words.end()) {
//        return 0;
//    }
//    int i = 0;
//    m[begin] = i++;
//    for (auto element : words)
//        m[element] = i++;
//    m[target] = i;
//    answer = bfs(begin, target, words) - 1;
//
//    return answer;
//}
//
//int main() {
//    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
//    cout << solution("hit", "cog", words);
//    return 0;
//}