//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct M {
//	int s, e;
//};
//
//bool compare(M m1, M m2) {
//	return m1.e == m2.e ? m1.s < m2.s : m1.e < m2.e;
//}
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//	vector<M> v(n);
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%d %d", &v[i].s, &v[i].e);
//
//	sort(v.begin(), v.end(), compare);
//
//	int ans = 0;
//	int endTime = 0;
//
//	for (int i = 0; i < n; i++) {
//		if (v[i].s >= endTime) {
//			endTime = v[i].e;
//			ans++;
//		}
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}