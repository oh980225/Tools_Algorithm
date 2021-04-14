//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<int> seq;
//vector<int> node[10001];
//
//void go(int l, int r) {
//	if (l >= r)
//		return;
//
//	int idx = l + 1;
//	for (; idx <= r; idx++) {
//		if (seq[idx] > seq[l])
//			break;
//	}
//
//	if (idx != l + 1) {
//		node[l].push_back(l + 1);
//		go(l + 1, idx - 1);
//	}
//	if (idx <= r) {
//		node[l].push_back(idx);
//		go(idx, r);
//	}
//}
//
//void post(int s) {
//	if (node[s].size())
//		post(node[s][0]);
//	if (node[s].size() > 1)
//		post(node[s][1]);
//
//	printf("%d\n", seq[s]);
//}
//
//int main() {
//	int num;
//	while (~scanf("%d", &num))
//		seq.push_back(num);
//	go(0, seq.size() - 1);
//	post(0);
//
//	return 0;
//}