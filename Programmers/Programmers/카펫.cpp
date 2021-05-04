//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//    int w = 0;
//    int h = 0;
//    for (int i = 1; i <= yellow; i++) {
//        if (yellow % i == 0) {
//            int temp = yellow / i;
//            if (brown == (temp + 2) * 2 + 2 * i) {
//                if (temp >= i) {
//                    w = temp + 2;
//                    h = i + 2;
//                }
//                else {
//                    w = i + 2;
//                    h = temp + 2;
//                }
//                break;
//            }
//        }
//    }
//
//    answer.push_back(w);
//    answer.push_back(h);
//
//    return answer;
//}
//
//int main() {
//    int b, y;
//    cin >> b >> y;
//
//    vector<int> ans = solution(b, y);
//
//    cout << ans[0] << ", " << ans[1] << endl;
//
//    return 0;
//}