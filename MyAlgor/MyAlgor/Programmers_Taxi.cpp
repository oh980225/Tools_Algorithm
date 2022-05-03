#include <string>
#include <vector>

using namespace std;

long long road[201][201];

const long long MAX_VALUE = 2e9;

void init(int n, vector<vector<int>>& fares) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) {
        continue;
      }
      road[i][j] = MAX_VALUE;
    }
  }

  for(auto fare : fares) {
    road[fare[0]][fare[1]] = fare[2];
    road[fare[1]][fare[0]] = fare[2];
  }
}

void floyd(int n) {
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        long long next = road[i][k] + road[k][j];
        if(road[i][j] > next) {
          road[i][j] = next;
        }
      }
    }
  }
}
 
int getMinFee(int n, int s, int a, int b) {
  long long result = MAX_VALUE;

  for(int i = 1; i <= n; i++) {
    result = min(road[s][i] + road[i][a] + road[i][b], result);
  }

  return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  init(n, fares);

  floyd(n);

  return getMinFee(n, s, a, b);
}