#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int main( ) {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z')
            printf("%c", str[i]);

        else {
            switch (str[i]) {

            case '(':
                s.push(str[i]);
                break;

            case '*':
            case '/':
                while (s.size() && (s.top() == '*' || s.top() == '/')) {
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(str[i]);
                break;

            case '+':
            case '-':
                while (s.size() && s.top() != '(') {
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(str[i]);
                break;

            case ')':
                while (s.size() && s.top() != '(') {
                    printf("%c", s.top());
                    s.pop();
                }
                s.pop();
                break;
            }
        }
    }

    while (s.size()) {
        printf("%c", s.top());
        s.pop();
    }

    return 0;
}
