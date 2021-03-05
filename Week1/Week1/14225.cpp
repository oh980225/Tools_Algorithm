//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, maxNum;
//int s[21];
//deque<int> q;
//
//int go(int x) {
//	if (s[0] != 1)
//		return 1;
//	if (s[x] > maxNum + 1) 
//		return maxNum + 1;
//	if (x >= n)
//		return maxNum + 1;
//
//	maxNum += s[x];
//
//	return go(x + 1);
//}
//
//int main() {
//	cin >> n;
//
//	int sum = 0;
//
//	for (int i = 0; i < n; i++) {
//		cin >> s[i];
//		sum += s[i];
//	}
//
//	sort(s, s + n);
//
//	cout << go(0);
//
//	return 0;
//}