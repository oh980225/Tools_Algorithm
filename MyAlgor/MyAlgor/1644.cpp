//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int  MAX = 4000000;
//int arr[MAX + 1];
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//	
//	if (n == 1) {
//		printf("0");
//		return 0;
//	}
//
//	for (int i = 2; i <= n; i++) {
//		arr[i] = i;
//	}
//
//	// 에라토스테네스의 체
//	for (int i = 2; i <= MAX; i++) {
//		for (int j = i + i; j <= MAX; j += i) {
//			arr[j] = 0;
//		}
//	}
//	vector<int> v;
//	for (int i = 2; i <= n; i++) {
//		if (!arr[i])
//			continue;
//		v.push_back(arr[i]);
//	}
//
//	int l = 0;
//	int r = 0;
//	int sum = v[0];
//	int cnt = 0;
//	while (l <= r && l < v.size() && r < v.size()) {
//		if (sum < n) {
//			r++;
//			if (r == v.size()) {
//				break;
//			}
//			sum += v[r];
//		}
//		else if (sum == n) {
//			cnt++;
//			sum -= v[l];
//			l++;
//		}
//		else {
//			sum -= v[l];
//			l++;
//		}
//	}
//
//	printf("%d", cnt);
//}