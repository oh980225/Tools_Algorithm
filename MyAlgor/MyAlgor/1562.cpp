#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main() {
	int n;
	scanf_s("%d", &n);

	if (n < 10) {
		printf("0");
		return 0;
	}
	if (n == 1) {
		printf("1");
		return 0;
	}

	int f = 9;
	int e = 0;
	int s = 10;
	arr[s] = 1;

	while (n - s > 0) {
		int nextF = f;
		int nextE = e;
		if (f < 9) {
			nextF++;
		}
		else {
			nextF--;
		}
		if (nextF == e || nextF == 0 || e == 0) {
			arr[s + 1] = (arr[s + 1] + arr[s]) % (int)1e9;
		}
		else {
			arr[s + 1] = (arr[s + 1] + 2 * arr[s]) % (int)1e9;
		}
		if (e < 9) {
			nextE++;
		}
		else {
			nextE--;
		}
		if (f == nextE || f == 0 || nextE == 0) {
			arr[s + 1] = (arr[s + 1] + arr[s]) % (int)1e9;
		}
		else {
			arr[s + 1] = (arr[s + 1] + 2 * arr[s]) % (int)1e9;
		}
		f = nextF;
		e = nextE;
		s++;
	}


	int sum = 0;

	for (int i = 1; i <= 40; i++) {
		sum += arr[i];
	}
	
	printf("%d", sum);

	return 0;
}