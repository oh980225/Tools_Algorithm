//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int N, M, ans;
//char board[50][50];
//char color[2][2] = { {'B', 'W'}, {'W', 'B'} };
//
//int checkBoard(int x, int y) {
//	int num = 1e9;
//
//	for (int i = 0; i < 2; i++) {
//		int sum = 0;
//		for (int j = 0; j < 8; j++) {
//			for (int k = 0; k < 8; k++) {
//				if (board[j + x][k + y] == color[j % 2][k % 2]) {
//					sum++;
//				}
//			}
//		}
//		num = min(num, sum);
//		swap(color	[0], color[1]);
//	}
//
//	return num;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		scanf("%s", board[i]);
//	}
//
//	int ans = 1e9;
//
//	for (int i = 0; i <= N - 8; i++) {
//		for (int j = 0; j <= M - 8; j++) {
//			ans = min(ans, checkBoard(i, j));
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}