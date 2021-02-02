//#include <iostream>
//
//using namespace std;
//
//int N;
//int M;
//int arr[9];
//bool checked[9];
//
//void func(int count) {
//	if (M == count) {
//		for (int i = 0; i < M; i++) {
//			cout << arr[i] << " ";
//		}
//		puts("");
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (!checked[i]) {
//			checked[i] = true;
//			arr[count] = i;
//			func(count + 1);
//			checked[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	cin >> M;
//
//	func(0);
//
//	return 0;
//}