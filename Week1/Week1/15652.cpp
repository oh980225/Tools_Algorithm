//#include <iostream>
//
//using namespace std;
//
//int N, M;
//
//int arr[9];
//
//void func(int cnt, int prev) {
//	if (cnt == M) {
//		for (int i = 0; i < cnt; i++) {
//			cout << arr[i] << " ";
//		}
//		puts("");
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (prev <= i) {
//			arr[cnt] = i;
//			func(cnt + 1, i);
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M;
//
//	func(0, 0);
//
//	return 0;
//}