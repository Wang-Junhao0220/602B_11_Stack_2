//
// Created by Junhao on 2023/6/1.
//
#include<bits/stdc++.h>

#define ll long long
using namespace std;
stack<int> p;
ll s[1500];
ll n;

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1, flag = 1; i <= n; i++) {
        while (flag <= s[i]) {
            p.push(flag++);
        }
        if (p.top() == s[i]) {
            p.pop();
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
