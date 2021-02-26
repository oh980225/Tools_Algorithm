//#include <iostream>
//
//using namespace std;
//
//int number[9];
//int ans;
//
//void buySet() {
//	for (int i = 0; i < 9; i++) {
//		if (i == 6) {
//			number[i] += 2;
//		}
//		else {
//			number[i] += 1;
//		}
//	}
//}
//
//int main() {
//	string door;
//
//	cin >> door;
//	
//	for (int i = 0; i < door.size(); i++) {
//		int doorNum = door[i] - '0';
//		if (doorNum == 9) {
//			doorNum = 6;
//		}
//		if (!number[doorNum]) {
//			ans += 1;
//			buySet();
//		}
//		number[doorNum]--;
//	}
//
//	cout << ans;
//
//	return 0;
//}