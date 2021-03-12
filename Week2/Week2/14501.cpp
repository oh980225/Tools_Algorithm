//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, ans, num;
//int tArr[16];
//int pArr[16];
//
//void go(int x) {
//	if (x > n) {
//		ans = max(ans, num);
//		return;
//	}
//
//	for (int i = x; i <= n; i++) {
//		if (i + tArr[i] > n + 1) {
//			go(i + tArr[i]);
//			continue;
//		}
//		num += pArr[i];
//		go(i + tArr[i]);
//		num -= pArr[i];
//	}
//
//	return;
//}
//
//
//int main() {
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> tArr[i] >> pArr[i];
//	}
//
//	go(1);
//
//	cout << ans;
//
//	return 0;
//}