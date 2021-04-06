//#include <bits/stdc++.h>
//
//using namespace std;
//
//int r, c;
//string matrix[51];
//int ans;
//
//struct MOVE {
//	int y, x;
//};
//
//MOVE moveArr[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//
//void bfs(int y, int x)
//{
//	int check[51][51] = { 0 };
//	queue<MOVE> q;
//
//	check[y][x] = 1;
//	q.push({ y, x });
//
//	while (!q.empty())
//	{
//		int curY = q.front().y;
//		int curX = q.front().x;
//		q.pop();
//		ans = max(ans, check[curY][curX] - 1);
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nY = curY + moveArr[i].y;
//			int nX = curX + moveArr[i].x;
//			if (0 <= nX && nX < c && 0 <= nY && nY < r && matrix[nY][nX] == 'L' && !check[nY][nX])
//			{
//				q.push({ nY, nX });
//				check[nY][nX] = check[curY][curX] + 1;
//			}
//		}
//	}
//}
//
//int main() {
//	scanf_s("%d %d", &r, &c);
//
//	for (int i = 0; i < r; i++) {
//		cin >> matrix[i];
//	}
//
//	for (int j = 0; j < r; j++) {
//		for (int k = 0; k < c; k++) {
//			if (matrix[j][k] == 'L')
//				bfs(j, k);
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}