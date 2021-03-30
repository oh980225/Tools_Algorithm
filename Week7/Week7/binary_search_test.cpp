//#include <bits/stdc++.h>
//
//using namespace std;
//
//int arr[15] = { 1, 3, 4, 6, 7, 8, 10, 12 ,15, 17, 19, 20, 21, 23, 24 };
//
//int binarySearch(int seq[], int num) {
//	int l = 0;
//	int r = sizeof arr / sizeof arr[0];
//
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (num == seq[mid])
//			return mid;
//		if (num < seq[mid])
//			r = mid - 1;
//		else
//			l = mid + 1;
//	}
//
//	return -1;
//}
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//
//	int result = binarySearch(arr, n);
//	printf("%d", result);
//
//	return 0;
//}