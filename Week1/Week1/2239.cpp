//#include<bits/stdc++.h>
//
//using namespace std;
//
//int matrix[9][9], ok;
//int num;
//int pre;
//
//struct AREA {
//	int s, e;
//};
//
//AREA area[9] = { {0,2}, {0,2}, {0,2}, {3,5}, {3,5}, {3,5}, {6,8}, {6,8}, {6,8} };
//
//bool check(int y, int x, int k) {
//	for (int i = 0; i < 9; i++) {
//		if (matrix[y][i] == k || matrix[i][x] == k) 
//			return 0;
//	}
//	for (int i = area[y].s; i <= area[y].e; i++) {
//		for (int j = area[x].s; j <= area[x].e; j++) {
//			if (matrix[i][j] == k)
//				return 0;
//		}
//	}
//
//	return 1;
//}
//
//void sol(int y, int x) {
//	if (ok) return;
//	if (y == 9) {
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) 
//				printf("%d", matrix[i][j]);
//			puts("");
//		}
//		ok = 1;
//		return;
//	}
//	if (matrix[y][x]) {
//		if (x == 8) 
//			sol(y + 1, 0);
//		else 
//			sol(y, x + 1);
//	}
//	else {
//		for (int i = 1; i < 10; i++) {
//			if (check(y, x, i)) {
//				matrix[y][x] = i;
//				if (x == 8) 
//					sol(y + 1, 0);
//				else 
//					sol(y, x + 1);
//				matrix[y][x] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	char c = NULL;
//	int i = 0;
//	int j = 0;
//	while (1) {
//		scanf_s("%c", &c);
//		num = c - '0';
//		if (c == '\n')
//			continue;
//		matrix[i][j] = num;
//		if (j < 8)
//			j++;
//		else {
//			i++;
//			j = 0;
//		}
//		if (i > 8) {
//			break;
//		}
//	}
//	
//	sol(0, 0);
//
//	return 0;
//}