#include <string>
#include <vector>

using namespace std;

long long solution(int w, int h) {
  long long answer;

  long long W = w;
  long long H = h;

  if (w == h) {
    answer = (W * H) - W;
  }

  else {
    long long a=W, b=H, c;
      
    while (b != 0) {
      c = a % b;
      a = b;
      b = c;
    }

    long long gcd = a;
    answer = (W * H) - (((W / gcd) + (H / gcd) - 1) * gcd);
  }

  return answer;
}