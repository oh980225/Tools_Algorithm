//#include <bits/stdc++.h>
//
//using namespace std;
//
//int memo[1000001];
//
//// bfs
//int main() {
//	int n;
//
//	scanf_s("%d", &n);
//
//	queue<int> q;
//	q.push(n);
//	memo[n] = 1;
//
//	while (q.size()) {
//		int front = q.front();
//		q.pop();
//
//		if (front == 1) {
//			printf("%d", memo[front] - 1);
//			return 0;
//		}
//
//		vector<int> next;
//		if (front % 3 == 0)
//			next.push_back(front / 3);
//		if (front % 2 == 0)
//			next.push_back(front / 2);
//		next.push_back(front - 1);
//
//		for (auto element : next) {
//			if (!memo[element]) {
//				memo[element] = memo[front] + 1;
//				q.push(element);
//			}
//		}
//	}
//
//	return 0;
//}

// bottom-up
//int main() {
//	int n;
//	scanf_s("%d", &n);
//
//	for (int i = 2; i <= n; i++) {
//		memo[i] = 1e9;
//		if (i % 3 == 0)
//			memo[i] = min(memo[i], memo[i / 3] + 1);
//		if (i % 2 == 0)
//			memo[i] = min(memo[i], memo[i / 2] + 1);
//		memo[i] = min(memo[i], memo[i - 1] + 1);
//	}
//
//	printf("%d", memo[n]);
//
//	return 0;
//}

// top-down
//int go(int x) {
//	if (x == 1)
//		return 0;
//
//	int& res = memo[x];
//
//	if (~res)
//		return res;
//
//	res = 1e9;
//
//	if (x % 3 == 0) {
//		res = min(res, go(x / 3) + 1);
//	}
//	if (x % 2 == 0) {
//		res = min(res, go(x / 2) + 1);
//	}
//
//	return res = min(res, go(x - 1) + 1);
//}
//
//int main() {
//	int n;
//
//	scanf_s("%d", &n);
//	memset(memo, -1, sizeof(memo));
//
//	printf("%d", go(n));
//
//	return 0;
//}