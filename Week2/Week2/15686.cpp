//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, m;
//int ans = 1e9;
//
//struct POS {
//	int y, x;
//};
//
//vector<POS> chicken;
//vector<POS> home;
//vector<int> p;
//
//int matrix[51][51];
//
//int main() {
//	scanf_s("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf_s("%1d", &matrix[i][j]);
//			if (matrix[i][j] == 1)
//				home.push_back({ i, j });
//			else if (matrix[i][j] == 2)
//				chicken.push_back({ i, j });
//		}
//	}
//
//	for (int i = 0; i < chicken.size(); i++) {
//		if (i >= chicken.size() - m)
//			p.push_back(1);
//		else
//			p.push_back(0);
//	}
//
//	do {
//		vector<POS> temp;
//
//		for (int i = 0; i < chicken.size(); i++) {
//			if (p[i]) {
//				temp.push_back(chicken[i]);
//			}
//		}
//		int result = 0;
//		for (int i = 0; i < home.size(); i++) {
//			int sum = 1e9;
//			for (auto element : temp) {
//				sum = min(sum, abs(home[i].x - element.x) + abs(home[i].y - element.y));
//			}
//			result += sum;
//		}
//		ans = min(ans, result);
//	} while (next_permutation(p.begin(), p.end()));
//
//	printf("%d", ans);
//
//	return 0;
//}