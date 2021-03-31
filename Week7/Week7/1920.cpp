//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<int> seq;
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//	seq.resize(n);
//
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &seq[i]);
//	}
//
//	sort(seq.begin(), seq.end());
//
//	int m;
//	scanf_s("%d", &m);
//
//	for (int i = 0; i < m; i++) {
//		int num;
//		scanf_s("%d", &num);
//		printf("%d\n", binary_search(seq.begin(), seq.end(), num));
//	}
//
//	return 0;
//}