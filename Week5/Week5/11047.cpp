//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int n, k;
//	scanf_s("%d %d", &n, &k);
//	vector<int> v(n);
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%d", &v[i]);
//
//	reverse(v.begin(), v.end());
//	
//	int ans = 0;
//	int i = 0;
//
//	while (i < n && k) {
//		ans += k / v[i];
//		k %= v[i];
//		i++;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}