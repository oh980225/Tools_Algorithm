//#include <bits/stdc++.h>
//
//using namespace std;
//
//set<int> s;
//int ans = 0;
//
//int main() {
//	int g, p;
//	scanf_s("%d %d", &g, &p);
//
//	for (int i = 0; i < g; i++)
//		s.insert(i + 1);
//
//	for (int i = 0; i < p; i++) {
//		if (s.empty())
//			break;
//		int num;
//		scanf_s("%d", &num);
//		auto it = s.lower_bound(num);
//		if (it == s.end())
//			it--;
//		if (it != s.end() && *it > num) {
//			if (it == s.begin())
//				break;
//			it--;
//		}
//		s.erase(it);
//		ans++;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}