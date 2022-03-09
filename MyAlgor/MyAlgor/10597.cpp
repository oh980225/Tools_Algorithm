#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int chk[55];
string input;
int maxNum = 0;

void dfs(int x) {
  if(x == input.size()) {
    for(auto element : ans) {
      cout << element << " ";
    }
    exit(0);
  }

  for (int i = 1; i <= 2; i++) {
    if(x + i - 1 >= input.size()) {
      continue;
    }
    
    int num = stoi(input.substr(x, i));

    if (num > maxNum) continue; 

    if (chk[num])continue;        

    ans.push_back(num);
    chk[num] = 1;

    dfs(x + i);

    chk[num] = 0;
    ans.pop_back();
  }
}

int main() {
  cin >> input;

  maxNum = input.size();
  if(input.size() >= 10) {
    maxNum = 9 + (input.size() - 9) / 2;
  }

  dfs(0);

  return 0;
}