//#include<bits/stdc++.h>
//
//using namespace std;
//
//int ans = 10e9;
//int n, num;
//int matrix[20][20];
//
//vector<int> v;
//vector<int> team1;
//vector<int> team2;
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> matrix[i][j];
//		}
//	}
//
//	v.resize(n);
//
//	for (int i = 0; i < n / 2; i++) {
//		v[i] = 0;
//	}
//	for (int i = n / 2; i < n; i++) {
//		v[i] = 1;
//	}
//
//	do {
//		for (int i = 0; i < n; i++) {
//			if (v[i]) {
//				team1.push_back(i);
//			}
//			else {
//				team2.push_back(i);
//			}
//		}
//
//		num = 0;
//		int temp1 = 0;
//		int temp2 = 0;
//
//		for (int i = 0; i < n / 2 - 1; i++) {
//			for (int j = i + 1; j < n / 2; j++) {
//				temp1 += (matrix[team1[i]][team1[j]] + matrix[team1[j]][team1[i]]);
//				temp2 += (matrix[team2[i]][team2[j]] + matrix[team2[j]][team2[i]]);
//			}
//		}
//		
//		num = temp2 - temp1;
//
//		if (num < 0)
//			num *= (-1);
//
//		ans = min(ans, num);
//
//		team1.clear();
//		team2.clear();
//	} while (next_permutation(v.begin(), v.end()));
//
//
//	cout << ans;
//
//	return 0;
//}