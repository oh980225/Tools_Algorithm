//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct LINE {
//	int s, e;
//};
//
//int ans;
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//	vector<LINE> v;
//
//	for (int i = 0; i < n; i++) {
//		int s, e;
//		scanf_s("%d %d", &s, &e);
//		if (v.empty())
//			v.push_back({ s, e });
//		else {
//			if (v.back().s <= s && s <= v.back().e)
//				v.back().e = max(e, v.back().e);
//			else
//				v.push_back({ s, e });
//		}
//	}
//
//	for (auto element : v) {
//		ans += element.e - element.s;
//	}
//
//	printf("%d", ans);
//
//	return 0;
//}