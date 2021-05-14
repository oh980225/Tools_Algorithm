//#include<bits/stdc++.h>
//using namespace std;
//int adj[505][505];
//int path[505][505];
//const int inf = 1e9;
//void FloydWarshall(int v) {
//	for (int k = 1; k <= v; ++k)
//		for (int i = 1; i <= v; ++i)
//			for (int j = 1; j <= v; ++j) {
//				int next = adj[i][k] + adj[k][j];
//				if (adj[i][j] > next) {
//					adj[i][j] = next;
//					path[i][j] = k;
//				}
//			}
//}
//
//void PrintPath(int u, int v) {
//	if (path[u][v] == u)
//		printf("%d ", u);
//	else
//		PrintPath(u, path[u][v]);
//	printf("%d ", v);
//}
//
//int main() {
//	memset(adj, 0x3f, sizeof(adj));
//	adj[1][2] = 1;
//	adj[1][4] = 10;
//	adj[2][3] = 2;
//	adj[2][4] = 6;
//	adj[3][4] = 2;
//
//	for (int i = 1; i <= 4; i++)
//		for (int j = 1; j <= 4; j++)
//			path[i][j] = i;
//
//	FloydWarshall(4);
//	
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= 4; j++) {
//			if (adj[i][j] == 1061109567)
//				cout << 'X' << " ";
//			else 
//				cout << adj[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	PrintPath(1, 4);
//
//	return 0;
//}