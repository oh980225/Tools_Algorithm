//#include <string>
//#include <vector>
//#include <map>
//#include <iostream>
//
//using namespace std;
//
//string solution(vector<string> participant, vector<string> completion) {
//    map<string, int> m;
//    string answer = "";
//
//    for (auto element : completion)
//        m[element]++;
//
//    for (auto element : participant) {
//        if (!m[element]) {
//            answer = element;
//            break;
//        }
//        m[element]--;
//    }
//    return answer;
//}
//
//int main() {
//    vector<string> participant;
//    vector<string> completion;
//    participant.push_back("mislav");
//    participant.push_back("stanko");
//    participant.push_back("mislav");
//    participant.push_back("mislav");
//    participant.push_back("ana");
//
//    completion.push_back("stanko");
//    completion.push_back("ana");
//    completion.push_back("mislav");
//    completion.push_back("mislav");
//
//    cout << solution(participant, completion);
//
//    return 0;
//}