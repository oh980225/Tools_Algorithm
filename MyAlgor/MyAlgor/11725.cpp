#include <bits/stdc++.h>

using namespace std;

int chk[100005];
vector<int> tree[100005];

void dfs(int x) {
	for (auto element : tree[x]) {
		if (!chk[element]) {
			chk[element] = x;
			dfs(element);
		}
	}
}

int main() {
	int n;
	scanf_s("%d", &n);

	int num1;
	int num2;
	for (int i = 1; i < n; i++) {
		scanf_s("%d %d", &num1, &num2);
		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}

	chk[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++) {
		printf("%d\n", chk[i]);
	}

	return 0;
}