//#include <bits/stdc++.h>
//
//using namespace std;
//
//char alph[5] = { 'a', 'e', 'i', 'o', 'u' };
//int l, c;
//vector<char> v;
//vector<int> p;
//vector<string> result;
//
//int main() {
//	scanf_s("%d %d", &l, &c);
//	v.resize(c);
//
//	for (int i = 0; i < c; i++) {
//		getchar();
//		scanf_s("%1c", &v[i]);
//		if (i >= c - l) {
//			p.push_back(1);
//		}
//		else {
//			p.push_back(0);
//		}
//	}
//
//	sort(v.begin(), v.end());
//
//	do {
//		string str = "";
//		int cond1 = 0;
//		int cond2 = 0;
//
//		for (int i = 0; i < c; i++) {
//			if (p[i]) {
//				str.append(1, v[i]);
//				if (find(alph, alph + 5, v[i]) != alph + 5)
//					cond1++;
//				else
//					cond2++;
//			}
//		}
//
//		if (cond1 == 0 || cond2 < 2)
//			continue;
//
//		result.push_back(str);
//	} while (next_permutation(p.begin(), p.end()));
//
//	reverse(result.begin(), result.end());
//
//	for (auto element : result)
//		cout << element << endl;
//
//	return 0;
//}