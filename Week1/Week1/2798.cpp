//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, m, ans;
//int minDiff = 1e9;
//vector<int> v;
//
//int main() {
//	cin >> n >> m;
//	v.resize(n);
//
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//
//	vector<int> p;
//
//	for (int i = 0; i < n - 3; i++) {
//		p.push_back(0);
//	}
//	for (int i = 0; i < 3; i++) {
//		p.push_back(1);
//	}
//
//	int total;
//
//	do {
//		total = 0;
//		for (int i = 0; i < n; i++) {
//			if (p[i]) {
//				total += v[i];
//			}
//		}
//
//		if (total > m) {
//			continue;
//		}
//
//		minDiff = min(minDiff, m - total);
//
//		if (minDiff == (m - total)) {
//			ans = total;
//			if (minDiff == 0) {
//				break;
//			}
//		}
//	} while (next_permutation(p.begin(), p.end()));
//
//	cout << ans;
//
//	return 0;
//}