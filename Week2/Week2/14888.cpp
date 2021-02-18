//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int>num;
//vector<int> p;
//int N;
//
//long long int maxAns = -1e9;
//long long int minAns = 1e9;
//
//int cal[4] = { 0, 1, 2, 3 };
//// 0 -> +
//// 1 -> -
//// 2 -> x
//// 3 -> /
//
//// 각 연산의 결과를 구하고 maxAns, minAns 최신화
//void calculateNum(long long int number) {
//	number = num[0];
//	for (int i = 0; i < N - 1; i++) {
//		if (p[i] == 0) { // -> +
//			number += num[i + 1];
//		}
//		else if (p[i] == 1) { // -> -
//			number -= num[i + 1];
//		}
//		else if (p[i] == 2) { // -> x
//			number *= num[i + 1];
//		}
//		else { // -> /
//			number /= num[i + 1];
//		}
//	}
//	maxAns = max(maxAns, number);
//	minAns = min(minAns, number);
//}
//
//int main() {
//	cin >> N;
//
//	num.resize(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//
//	int count;
//
//	for (int i = 0; i < 4; i++) {
//		cin >> count;
//		for (int j = 0; j < count; j++) {
//			p.push_back(cal[i]);
//		}
//	}
//
//	// 순열을 이용해서 모든 연산 경우 확인
//	do {
//		long long int start = 0;
//		calculateNum(start);
//	} while (next_permutation(p.begin(), p.end()));
//
//	cout << maxAns;
//	puts("");
//	cout << minAns;
//
//	return 0;
//}