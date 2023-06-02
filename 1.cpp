//
// Created by Junhao on 2023/6/1.
//
/*
 * 题目描述：
 * 从键盘读入一个后缀表达式（字符串），只含有 0-9 组成的运算数及加（+）、减（-）、
 * 乘（*）、整除（/）四种运算符。每个运算数之间用一个空格隔开，不需要判断给你的表达
 * 式是否合法。要求输出该表达式的值。
 * --------------------------------------------------------
 * 例如：
 * 输入：16 9 4 3 + * -
 * 输出：-47
 * --------------------------------------------------------
 * @author: Junhao Wang
 * @date: 6/1/2021
*/
#include <bits/stdc++.h>

#define ll long long
using namespace std;
stack<ll> stk;
string s;

int main() {
    getline(cin, s);
    ll len = s.length(), x = 0, y = 0;
    for (ll i = 0; i < len; i++) {
        if (s[i] == ' ') continue;//跳过空格
        if (s[i] == '+') {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            stk.push(x + y);
        } else if (s[i] == '-') {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            stk.push(y - x);
        } else if (s[i] == '*') {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            stk.push(x * y);
        } else if (s[i] == '/') {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            stk.push(y / x);
        } else {
            x = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                x = x * 10 + s[i] - '0';
                i++;
            }
            stk.push(x);
        }
    }
    cout << stk.top() << endl;
    return 0;
}