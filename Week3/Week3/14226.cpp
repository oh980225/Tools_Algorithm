//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int s;
//int check[1001][1001];
//
//struct EMO {
//	int num, copy;
//};
//
//int main() {
//	cin >> s;
//
//	check[1][0] = 1;
//	queue<EMO> q;
//	q.push({ 1, 0 });
//
//	while (q.size()) {
//		auto front = q.front();
//		q.pop();
//		int num = front.num;
//		int copy = front.copy;
//		if (num == s) {
//			cout << check[num][copy] - 1;
//			return 0;
//		}
//		int dNum[] = { num, num + copy, num - 1 };
//		int dCopy[] = { num, copy, copy };
//		for (int i = 0; i < 3; i++) {
//			if (0 <= dNum[i] && dNum[i] < 1001 && 0 <= dCopy[i] && dCopy[i] < 1001 && check[dNum[i]][dCopy[i]] == 0) {
//				q.push({ dNum[i], dCopy[i] });
//				check[dNum[i]][dCopy[i]] = check[num][copy] + 1;
//			}
//		}
//	}
//
//	return 0;
//}