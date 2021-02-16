//Bitmask 이용 풀이 
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, S, ans;
//
//int main() {
//	cin >> N >> S;
//
//	vector<int> v(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//	}
//
//	for (int i = (1 << N) - 1; i > 0; i--) {
//		int sum = 0;
//		for (int j = 0; j < N; j++) {
//			if (i & (1 << j)) {
//				sum += v[j];
//			}
//		}
//		if (sum == S) {
//			ans++;
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}


// 순열 이용 풀이
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, S, ans;
//
//int main() {
//	cin >> N >> S;
//
//	vector<int> v(N);
//	vector<vector<int>> matrix(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//		for (int j = 0; j < N; j++) {
//			if (j < (N - i - 1)) {
//				matrix[i].push_back(0);
//			}
//			else {
//				matrix[i].push_back(1);
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		do {
//			int sum = 0;
//			for (int j = 0; j < N; j++) {
//				if (matrix[i][j]) {
//					sum += v[j];
//				}
//			}
//			if (S == sum) {
//				ans++;
//			}
//
//		} while (next_permutation(matrix[i].begin(), matrix[i].end()));
//	}
//	
//	cout << ans;
//
//	return 0;
//}


// 재귀함수 풀이
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> v;
//int N, S, ans;
//
//void func(int toCheck, int sum, int preCheck) {
//	if (toCheck == 0) {
//		if (S == sum) {
//			ans++;
//		}
//		return;
//	}
//	for (int i = preCheck + 1; i < N; i++) {
//		func(toCheck - 1, sum + v[i], i);
//	}
//}
//
//int main() {
//	cin >> N >> S;
//
//	v.resize(N);
//
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//	}
//
//	for (int i = 1; i <= N; i++) {
//		func(i, 0, -1);
//	}
//
//	cout << ans;
//
//	return 0;
//}