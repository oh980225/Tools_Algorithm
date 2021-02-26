//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int n, k;
//int check[100001];
//queue<int> q;
//
//int main() {
//	cin >> n >> k;
//
//	if (n >= k) {
//		cout << n - k;
//		return 0;
//	}
//
//	q.push(n);
//	check[n] = 1;
//
//	while (q.size()) {
//		int pos = q.front();
//		q.pop();
//		if (pos == k) {
//			cout << check[pos] - 1;
//			return 0;
//		}
//
//		int dx[] = { pos - 1, pos + 1, pos * 2 };
//
//		for (int i = 0; i < 3; i++) {
//			if (0 <= dx[i] && dx[i] < 100001 && check[dx[i]] == 0) {
//				check[dx[i]] = check[pos] + 1;
//				q.push(dx[i]);
//			}
//		}
//	}
//
//	return 0;
//}