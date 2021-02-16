#include <iostream>

using namespace std;

int N, ans;
int board[20][20];
int preBoard[20][20][20];
int moveQ[3][2] = { {1, 1}, {1, 0}, {1, -1} };

void checkBoard(int i, int j) {
	int nextX;
	int nextY;
	for (int k = 0; k < 3; k++) {
		nextX = i;
		nextY = j;
		while (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
			board[nextX][nextY] = 1;
			nextX += moveQ[k][0];
			nextY += moveQ[k][1];
		}
	}
}

void saveBoard(int seq) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			preBoard[seq][i][j] = board[i][j];
		}
	}
}

void getBackBoard(int seq) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = preBoard[seq][i][j];
		}
	}
}

void func(int row) {
	if (row >= N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!board[row][i]) {
			saveBoard(i);
			checkBoard(row, i);
			func(row + 1);
			getBackBoard(i);
		}
	}
}

int main() {
	cin >> N;

	func(0);

	cout << ans;

	return 0;
}