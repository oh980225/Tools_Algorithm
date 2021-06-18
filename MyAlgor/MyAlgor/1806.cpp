//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, s;
//
//int main() {
//	scanf_s("%d %d", &n, &s);
//	vector<int> v(n);
//
//	for (int i = 0; i < n; i++) 
//		scanf_s("%d", &v[i]);
//
//	int l = 0;
//	int r = 0;
//	int sum = v[0];
//	int len = 1e9;
//
//	while (l <= r && r < n) {
//		if (sum < s) {
//			r++;
//			if (r >= n)
//				break;
//			sum += v[r];
//		}
//		else if (sum == s) {
//			len = min(len, r - l + 1);
//			r++;
//			if (r >= n)
//				break;
//			sum += v[r];
//		}
//		else {
//			len = min(len, r - l + 1);
//			sum -= v[l];
//			l++;
//		}
//	}
//
//	if (len == 1e9)
//		printf("0");
//	else
//		printf("%d", len);
//
//	return 0;
//}