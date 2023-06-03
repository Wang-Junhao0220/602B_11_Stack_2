#include<iostream>
#include<string>

using namespace std;

const int mod = 1e4;

int main() {
    string s;
    cin >> s;
    long long num = 0, prod = 1, sum = 0;
    s += '+';
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            num %= mod;
        }
        else if (c == '*') {
            prod *= num;
            prod %= mod;
            num = 0;
        }
        else if (c == '+') {
            prod *= num;
            prod %= mod;
            sum += prod;
            sum %= mod;
            num = 0;
            prod = 1;
        }
    }
    cout << sum << endl;
    return 0;
}
