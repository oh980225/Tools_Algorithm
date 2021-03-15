//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int n, m;
//
//	scanf("%d %d", &n, &m);
//	vector<int> v(n + 1);
//
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &v[i]);
//		v[i] += v[i - 1];
//	}
//
//	int i, j;
//
//	for (int k = 0; k < m; k++) {
//		scanf("%d %d", &i, &j);
//		cout << v[j] - v[i - 1] << '\n';
//	}
//
//	return 0;
//}