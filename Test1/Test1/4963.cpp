//#include <iostream>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int board[50][50];
//int check[50][50];
//
//bool isEnd = false;
//int w, h, ans;
//
//int dPos[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
//
//
//void func(int i, int j) {
//	if (!check[i][j]) {
//		check[i][j] = 1;
//		if (board[i][j]) {
//			isEnd = true;
//			for (int k = 0; k < 8; k++) {
//				int moveI = i + dPos[k][0];
//				int moveJ = j + dPos[k][1];
//				if (0 <= moveI && moveI < h && 0 <= moveJ && moveJ < w) {
//					func(moveI, moveJ);
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	while (1) {
//		cin >> w >> h;
//		if (w == 0 && h == 0) {
//			break;
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				cin >> board[i][j];
//			}
//		}
//
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				func(i, j);
//				if (isEnd) {
//					ans += 1;
//				}
//				isEnd = false;
//			}
//		}
//
//		cout << ans << endl;
//
//		ans = 0;
//		memset(board, 0, sizeof(board));
//		memset(check, 0, sizeof(check));
//	}
//
//
//	return 0;
//}