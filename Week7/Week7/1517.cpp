//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll ans;
//int n;
//vector<int> seq;
//
//void merge(vector<int>& seq, int l, int r) {
//	vector<int> tmp;
//	int mid = (l + r) / 2;
//	int f = l;
//	int s = mid + 1;
//
//	while (f <= mid && s <= r) {
//		if (seq[f] <= seq[s])
//			tmp.push_back(seq[f++]);
//		else {
//			tmp.push_back(seq[s++]);
//			ans += mid - f + 1;
//		}
//	}
//
//	for (; f <= mid; f++)
//		tmp.push_back(seq[f]);
//	for (; s <= r; s++)
//		tmp.push_back(seq[s]);
//	for (int i = l; i <= r; i++)
//		seq[i] = tmp[i - l];
//}
//
//void mergeSort(vector<int>& seq, int l, int r) {
//	if (l < r) {
//		int mid = (l + r) / 2;
//		mergeSort(seq, l, mid);
//		mergeSort(seq, mid + 1, r);
//		merge(seq, l, r);
//	}
//}
//
//int main() {
//	scanf_s("%d", &n);
//	seq.resize(n);
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%d", &seq[i]);
//
//	mergeSort(seq, 0, n - 1);
//
//	printf("%lld", ans);
//
//	return 0;
//}#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll ans;
//int n;
//vector<int> seq;
//
//void merge(vector<int>& seq, int l, int r) {
//	vector<int> tmp;
//	int mid = (l + r) / 2;
//	int f = l;
//	int s = mid + 1;
//
//	while (f <= mid && s <= r) {
//		if (seq[f] <= seq[s])
//			tmp.push_back(seq[f++]);
//		else {
//			tmp.push_back(seq[s++]);
//			ans += mid - f + 1;
//		}
//	}
//
//	for (; f <= mid; f++)
//		tmp.push_back(seq[f]);
//	for (; s <= r; s++)
//		tmp.push_back(seq[s]);
//	for (int i = l; i <= r; i++)
//		seq[i] = tmp[i - l];
//}
//
//void mergeSort(vector<int>& seq, int l, int r) {
//	if (l < r) {
//		int mid = (l + r) / 2;
//		mergeSort(seq, l, mid);
//		mergeSort(seq, mid + 1, r);
//		merge(seq, l, r);
//	}
//}
//
//int main() {
//	scanf_s("%d", &n);
//	seq.resize(n);
//
//	for (int i = 0; i < n; i++)
//		scanf_s("%d", &seq[i]);
//
//	mergeSort(seq, 0, n - 1);
//
//	printf("%lld", ans);
//
//	return 0;
//}