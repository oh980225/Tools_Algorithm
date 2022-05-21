#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void moveIt(int from, int to) {
  answer.push_back({from, to});
}

void dfs(int n, int from, int to, int via) {
  if(n == 1) {
    moveIt(from ,to);
    return;
  }

  dfs(n - 1, from, via, to);
  moveIt(from, to);
  dfs(n - 1, via, to, from);
}

vector<vector<int>> solution(int n) {
  dfs(n, 1, 3, 2);
  
  return answer;
}