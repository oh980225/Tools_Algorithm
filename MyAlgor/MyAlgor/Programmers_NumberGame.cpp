#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
  return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int size = A.size();

    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end(), compare);
    
    int aPointer = 0;
    int bPointer = 0;

    while(aPointer < size && bPointer < size) {
      while(A[aPointer] >= B[bPointer]) {
        aPointer++;

        if(aPointer >= size) {
          break;
        }
      }

      if(aPointer < size) {
        answer++;
      }

      aPointer++;
      bPointer++;
    }

    return answer;
}