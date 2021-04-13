#include <bits/stdc++.h>

using namespace std;

vector<int> vec[51];
int del;

int go(int s) {
	if (s == del)
		return 0;
	if (vec[s].empty() || (vec[s].size() == 1 && vec[s][0] == del))
		return 1;
	
	int ans = 0;
	for (int i = 0; i < vec[s].size(); i++)
		ans += go(vec[s][i]);

	return ans;
}

int main() {
	int n;
	int root = 0;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf_s("%d", &num);
		if (num == -1)
			root = i;
		else
			vec[num].push_back(i);
	}
	scanf_s("%d", &del);
	printf("%d", go(root));

	return 0;
}