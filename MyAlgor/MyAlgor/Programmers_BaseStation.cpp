#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int size = w * 2 + 1;
    int pre = 1;

    for(auto element : stations) {
      if(element - w - pre <= 0) {
        pre = element + w + 1;
        continue;
      }

      answer += ceil((float) (element - w - pre) / size);
      pre = element + w + 1;
    }

    if(pre <= n) {
      answer += ceil((float) (n - pre + 1) / size);
    }

    return answer;
}