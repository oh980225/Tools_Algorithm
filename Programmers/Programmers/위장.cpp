//#include <string>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//map<string, int> m;
//
//int solution(vector<vector<string>> clothes) {
//    int answer = 1;
//
//    for (int i = 0; i < clothes.size(); i++) {
//        if (!m[clothes[i][1]]) {
//            m[clothes[i][1]] = 1;
//        }
//        else {
//            m[clothes[i][1]] += 1;
//        }
//    }
//    
//    for (auto element : m) {
//        answer *= (element.second + 1);
//    }
//    
//    return answer - 1;
//}
//
//int main() {
//    vector<vector<string>> clothes = { {"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face"} };
//
//
//    cout << solution(clothes);
//
//    return 0;
//}