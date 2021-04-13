//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<int> vec[33];
//
//void pre(int s) {
//	if (s == -1)
//		return;
//	printf("%c", s + 'A');
//	pre(vec[s][0]);
//	pre(vec[s][1]);
//}
//
//void in(int s) {
//	if (s == -1)
//		return;
//	in(vec[s][0]);
//	printf("%c", s + 'A');
//	in(vec[s][1]);
//}
//
//void post(int s) {
//	if (s == -1)
//		return;
//	post(vec[s][0]);
//	post(vec[s][1]);
//	printf("%c", s + 'A');
//}
//
//int main() {
//	int n;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++) {
//		char msg[3];
//		for(int j=0; j<3; j++)
//			cin >> msg[j];
//		int p = msg[0] - 'A';
//		int l = -1;
//		int r = -1;
//
//		if (msg[1] != '.')
//			l = msg[1] - 'A';
//		if (msg[2] != '.')
//			r = msg[2] - 'A';
//
//		vec[p].push_back(l);
//		vec[p].push_back(r);
//	}
//
//	pre(0);
//	puts("");
//	in(0);
//	puts("");
//	post(0);
//
//
//	return 0;
//}