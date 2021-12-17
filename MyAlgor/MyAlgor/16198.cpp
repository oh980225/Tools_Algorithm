#include <iostream>
#include <vector>

using namespace std;

int n;
int result = 0;

void func(int sum, vector<int> balls) {
  if (balls.size() <= 2) {
    result = max(result, sum);
    return;
  }

  for (int i = 1; i < balls.size() - 1; i++) {
    int energy = balls[i - 1] * balls[i + 1];
    int idx = 0;
    vector<int> others;
    for (auto ball : balls) {
      if (idx++ == i) {
        continue;
      }
      others.push_back(ball);
    }
    func(sum + energy, others);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> balls;


  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    balls.push_back(num);
  }

  func(0, balls);

  cout << result;

  return 0;
}