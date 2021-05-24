//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, m;
//int matrix[105][105];
//
//int main() {
//	cin >> n >> m;
//	memset(matrix, 0x3f, sizeof(matrix));
//	for (int i = 0; i < m; i++) {
//		int f, s;
//		cin >> f >> s;
//		matrix[f][s] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			for (int k = 1; k <= n; k++) {
//				matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		int cnt = 0;
//		for (int j = 1; j <= n; j++) {
//			if (i == j) {
//				continue;
//			}
//			if (matrix[i][j] != 1061109567) {
//				cnt++;
//			}
//		}
//		for (int j = 1; j <= n; j++) {
//			if (i == j) {
//				continue;
//			}
//			if (matrix[j][i] != 1061109567) {
//				cnt++;
//			}
//		}
//		cout << n -1 - cnt << endl;
//	}
//
//	return 0;
//}