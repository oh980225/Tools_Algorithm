#include <bits/stdc++.h>

using namespace std;

int N;
char types[123457];
vector<int> tree[123457];
long long numbers[123457]; 

void input() {
  cin >> N;

  char type;
  int num;
  int to;
  types[1] = 'S';
  numbers[1] = 0;

  for(int i = 2; i <= N; i++) {
    cin >> type >> num >> to;
    types[i] = type;
    numbers[i] = num;
    tree[to].push_back(i);
  }
}

long long moveSheep(int num) {
  long long count = 0; 
  for(int i = 0; i < tree[num].size(); i++) 
    count += moveSheep(tree[num][i]);

  if(types[num] == 'W') {
    count -= numbers[num];
    if(count < 0)
      return 0;
    return count;
  }

  return count + numbers[num];
}

int main() {
  input();

  cout << moveSheep(1);

  return 0;
}