//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n;
//
//int main() {
//	cin >> n;
//
//	for (int i = 1; i < n; i++) {
//		int sum = i;
//		int temp = i;
//		while (temp != 0) {
//			sum += (temp % 10);
//			temp /= 10;
//		}
//		if (sum == n) {
//			cout << i;
//			return 0;
//		}
//	}
//
//	cout << 0;
//
//	return 0;
//}