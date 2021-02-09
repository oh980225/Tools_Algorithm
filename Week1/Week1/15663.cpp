//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//
//int arr[9];
//bool checked[9];
//vector<int> v;
//
//void func(int cnt) {
//	if (cnt == M) {
//		for (int i = 0; i < cnt; i++) {
//			cout << arr[i] << " ";
//		}
//		puts("");
//		return;
//	}
//
//	int preNum = 0;
//
//	for (int i = 0; i < v.size(); i++) {
//		if (!checked[i] && preNum != v[i]) {
//			checked[i] = true;
//			preNum = v[i];
//			arr[cnt] = v[i];
//			func(cnt + 1);
//			checked[i] = false;
//		}
//	}
//}
//
//int main() {
//	int num;
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		cin >> num;
//		v.push_back(num);
//	}
//
//	sort(v.begin(), v.end());
//
//	func(0);
//
//	return 0;
//}