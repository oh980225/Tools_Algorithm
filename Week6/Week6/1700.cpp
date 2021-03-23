//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<priority_queue<int>> pq;
//vector<int> plug;
//int chk[101], ans;
//
//int getMax() {
//	int m = 0;
//	int mi = 0;
//	for (int i = 0; i < plug.size(); i++) {
//		if (pq[plug[i]].empty())
//			return i;
//		else if (-pq[plug[i]].top() > m) {
//			m = -pq[plug[i]].top();
//			mi = i;
//		}
//	}
//	return mi;
//}
//
//int main() {
//	int n, k;
//	scanf_s("%d %d", &n, &k);
//	vector<int> seq(k);
//	pq.resize(k + 1);
//	int cur = 0;
//
//	for (int i = 0; i < k; i++) {
//		scanf_s("%d", &seq[i]);
//		pq[seq[i]].push(-i);
//
//		if (plug.size() < n && !chk[seq[i]]) {
//			plug.push_back(seq[i]);
//			pq[seq[i]].pop();
//			chk[seq[i]] = 1;
//			cur = i;
//		}
//		else if (plug.size() < n && chk[seq[i]]) 
//			pq[seq[i]].pop();
//	}
//
//	for (int i = cur + 1; i < k; i++) {
//		if (chk[seq[i]] == 0) {
//			int step = getMax();
//			chk[plug[step]] = 0;
//			plug[step] = seq[i];
//			chk[seq[i]] = 1;
//			ans++;
//		}
//		pq[seq[i]].pop();
//	}
//
//	printf("%d", ans);
//
//	return 0;
//} 