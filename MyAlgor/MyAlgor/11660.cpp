//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, m;
//int matrix[1050][1050];
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	int num;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> num;
//			matrix[i + 1][j + 1] = matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j] + num;
//		}
//	}
//
//	int x1, y1, x2, y2;
//
//	for (int i = 0; i < m; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		int result = matrix[x2][y2] - matrix[x1 - 1][y2] - matrix[x2][y1 - 1] + matrix[x1 - 1][y1 - 1];
//		cout << result << "\n";
//	}
//
//	return 0;
//}