#include <bits/stdc++.h>

using namespace std;

int N, M;
int matrix[1001][1001];
int check[1001][1001];
int zero[1001][1001];

int dY[] = {0, 0, -1, 1};
int dX[] = {1, -1, 0, 0};

struct POS {
  int y, x;
};

vector<POS> v;
vector<int> zeroNum;

void input() {
  cin >> N >> M;
  string inputStr;
  for(int i = 0; i < N; i++) {
    cin >> inputStr;
    int idx = 0;
    for(auto str : inputStr) {
      matrix[i][idx] = str - '0';
      if(matrix[i][idx]) {
        v.push_back({i, idx});
      }
      idx += 1;
    }
  }
}

void checkWall() {
  for(auto position : v) {
    int count = 1;
    set<int> s;

    for(int i = 0; i < 4; i++) {
      int newY = position.y + dY[i];
      int newX = position.x + dX[i];

      if(0 <= newY && newY < N && 0 <= newX && newX < M && !matrix[newY][newX]) {
        if(s.find(zero[newY][newX]) == s.end()) {
          s.insert(zero[newY][newX]);
          count += zeroNum[zero[newY][newX]];
        }
      }
    }

    matrix[position.y][position.x] = count;
  }
}

void checkZeroArea() {
  int number = 0;
  zeroNum.push_back(-1);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(!matrix[i][j] && !check[i][j]) {
        queue<POS> q;
        q.push({i, j});
        check[i][j] = 1;
        number++;
        zero[i][j] = number;
        int count = 1;

        while(!q.empty()) {
          POS cur = q.front();
          q.pop();

          for(int i = 0; i < 4; i++) {
            int newY = cur.y + dY[i];
            int newX = cur.x + dX[i];

            if(0 <= newY && newY < N && 0 <= newX && newX < M && !check[newY][newX] && !matrix[newY][newX]) {
              check[newY][newX] = 1;
              count++;
              zero[newY][newX] = number;
              q.push({newY, newX});
            }
          }
        }

        zeroNum.push_back(count);
      }
    }
  }
}


void printNewMap() {
  checkZeroArea();

  checkWall();
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << matrix[i][j] % 10;
    }
    cout << "\n";
  }
}

int main() {
  input();
  
  printNewMap();

  return 0;
}