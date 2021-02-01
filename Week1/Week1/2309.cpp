#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 역발상 for문으로 해결
vector<int> seq;

int main() {
	int sum = 0;
	int num;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		seq.push_back(num);
		sum += num;
	}
	
	sort(seq.begin(), seq.end());

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - seq[i] - seq[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << seq[k] << endl;
					}
				}

				return 0;
			}
		}
	}

	return 0;
}

// 순열 응용
//vector<int> p(2);
//vector<int> seq;
//
//int main() {
//	int num;
//	int sum;
//
//	for (int i = 0; i < 9; i++) {
//		cin >> num;
//		seq.push_back(num);
//		if (i < 7) {
//			p.push_back(1);
//		}
//	}
//
//	sort(seq.begin(), seq.end());
//
//	do {
//		sum = 0;
//
//		for (int i = 0; i < 9; i++) {
//			if (p[i]) {
//				sum += seq[i];
//			}
//		}
//
//		if (sum == 100) {
//			for (int i = 0; i < 9; i++) {
//				if (p[i]) {
//					cout << seq[i] << endl;
//				}
//			}
//			return 0;
//		}
//	
//	} while (next_permutation(p.begin(), p.end()));
//
//	return 0;
//}