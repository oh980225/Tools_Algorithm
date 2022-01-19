#include <bits/stdc++.h>

using namespace std;

int N, M, H;
vector<int> blocks[51];
int memo[51][1001];

void input() {
  cin >> N >> M >> H;
  cin.ignore();

  for(int i = 1; i <= N; i++) {
    string str;
    getline(cin, str);
    for(int j = 0; j < str.size(); j++) 
      if(str[j] == ' ' || j == 0) {
				blocks[i].push_back(stoi(&str[j]));
      }
  }
}

void output() {
  cout << memo[N][H];
}

void buildBlocks() {
  for(int i = 0; i <= N; i++) {
    memo[i][0] = 1; 
  }

  for(int i = 1; i <= N; i++) {
    for(int h = 1; h <= H; h++) {
      for(int k = 0; k < blocks[i].size(); k++) {
        if(h >= blocks[i][k]) {
          memo[i][h] += memo[i - 1][h - blocks[i][k]];
          memo[i][h] %= 10007;
        }
      }
      memo[i][h] += memo[i - 1][h];
      memo[i][h] %= 10007;
    }
  }
}

int main() {
  input();

  buildBlocks();

  output();

  return 0;
}