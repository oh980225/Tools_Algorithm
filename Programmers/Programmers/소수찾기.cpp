#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans;
int arr[7];
int chk[7];
bool checkNum[10000000];
string str;

bool isPrime(int num) {
    if (num < 2)
        return false;

    int a = (int)sqrt(num);

    for (int i = 2; i <= a; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}


void dfs(int cnt, int n) {
    if (cnt == n) {
        int number = 0;

        for (int i = 1; i <= n; i++) {
            number += arr[i - 1] * pow(10, n - i);
        }

        if (!checkNum[number]) {
            checkNum[number] = true;

            if (isPrime(number))
                ans++;
        }

        return;
    }

    for (int i = 0; i < str.size(); i++) {
        if (!chk[i]) {
            chk[i] = true;
            arr[cnt] = str[i] - '0';
            dfs(cnt + 1, n);
            chk[i] = false;
        }
    }

    return;
}


int solution(string numbers) {
    int answer = 0;
    str = numbers;

    for (int i = 1; i <= numbers.size(); i++) {
        dfs(0, i);
    }

    answer = ans;

    return answer;
}

int main() {
    cin >> str;

    cout << solution(str);

    return 0;
}