#include <string>
#include <vector>

using namespace std;

int arr[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 1; i <= n; i++) 
        arr[i] = 1;

    for (auto el : reserve) 
        arr[el]++;
    
    for (auto el : lost) 
        arr[el]--;
    
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 2 && 1 < i && !arr[i - 1]) {
            arr[i - 1]++;
            arr[i]--;
        }
        if (arr[i] == 2 && i < n && !arr[i + 1]) {
            arr[i + 1]++;
            arr[i]--;
        }
    }
    for (int i = 1; i <= n; i++)
        if (arr[i] > 0)
            answer++;
    return answer;
}

int main() {
    vector<int> lost;
    vector<int> re;
    lost.push_back(2);
    lost.push_back(4);
    //re.push_back(1);
    re.push_back(3);
    //re.push_back(5);
    int answer = solution(5, lost, re);
    printf("%d\n", answer);
    return 0;
}
