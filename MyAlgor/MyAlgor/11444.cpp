#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<vector<ll>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
    ll size = a.size();
    matrix temp(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) {
        for (ll j = 0; j < size; j++) {
            for (ll k = 0; k < size; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000000007;
        }
    }

    return temp;
}

matrix powMatrix(matrix a, ll n) {
    ll size = a.size();
    matrix temp(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) { 
        temp[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            temp = temp * a;
        }
        n /= 2;
        a = a * a;
    }
    return temp;

}

int main(void) {
    ll n;
    scanf_s("%lld", &n);
    matrix temp = { {1, 1}, {1, 0} };
    matrix answer = (powMatrix(temp, n - 1));
    int result = (answer[1][0] + answer[1][1]) % 1000000007;
    printf("%d", result);

    return 0;
}