// Use DeQue
//#include<bits/stdc++.h>
//
//using namespace std;
//int chk[100001];
//deque<int> dq;
//int n, k;
//
//int main() {
//	cin >> n >> k;
//	memset(chk, -1, sizeof(chk));
//
//	chk[n] = 0;
//	dq.push_back(n);
//
//	while (dq.size()) {
//		int cur = dq.front();
//		dq.pop_front();
//
//		if (cur == k) {
//			cout << chk[cur];
//		}
//
//		int dX[] = { {2 * cur}, {cur + 1}, {cur - 1} };
//		int dT[] = { 0,1,1 };
//
//		for (int i = 0; i < 3; i++) {
//			if (0 <= dX[i] && dX[i] < 100001 && chk[dX[i]] == -1) {
//				chk[dX[i]] = chk[cur] + dT[i];
//				if (i == 0) {
//					dq.push_front(dX[i]);
//				}
//				else {
//					dq.push_back(dX[i]);
//				}
//			}
//		}
//	}
//
//	return 0;
//}




// Use Two Queue
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int chk[100001];
//queue<int> q1, q2;
//int n, k;
//
//int main() {
//	cin >> n >> k;
//	memset(chk, -1, sizeof(chk));
//
//	chk[n] = 0;
//	q1.push(n);
//
//	while (q1.size() || q2.size()) {
//		int cur;
//
//		if (q1.size()) {
//			cur = q1.front();
//			q1.pop();
//		}
//		else {
//			cur = q2.front();
//			q2.pop();
//		}
//
//		if (cur == k) {
//			cout << chk[cur];
//		}
//
//		int dX[] = { {2 * cur}, {cur + 1}, {cur - 1} };
//		int dT[] = { 0,1,1 };
//
//		for (int i = 0; i < 3; i++) {
//			if (0 <= dX[i] && dX[i] < 100001 && chk[dX[i]] == -1) {
//				chk[dX[i]] = chk[cur] + dT[i];
//				if (i == 0) {
//					q1.push(dX[i]);
//				}
//				else {
//					q2.push(dX[i]);
//				}
//			}
//		}
//	}
//
//	return 0;
//}