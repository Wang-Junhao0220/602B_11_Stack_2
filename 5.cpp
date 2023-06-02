//
// Created by Junhao on 2023/6/1.
//
/*
 * 题目描述：
 * 给定一个只包含加法和乘法的算术表达式，请编程计算表达式的值。
 * --------------------------------------------------------
 * 输入样式：
 * 一行，为需要计算的表达式。表达式中只包含数字、加法运算符“+”和乘法运算符
 * “*”，且没有括号，所有参与运算的数字均为 0~2^31-1 之间的整数。输入数据保证这
 * 一行只有 0~9、+、* 这 12 种字符。
 * 输出样式：
 * 一行，一个整数，表示这个表达式的值。
 * 注意：当答案长度多于 4 位时，请只输出最后 4 位，前导 0 不输出。
 * 输入样例1：
 * 1+1*3+4
 * 输出样例1：
 * 8
 * 输入样例2：
 * 1+1000000003*1
 * 输出样例2：
 * 4
 * --------------------------------------------------------
 * 数据范围：
 * 对于 30% 的数据，0≤表达式中加法运算符和乘法运算符的总数≤100。
 * 对于 80% 的数据，0≤表达式中加法运算符和乘法运算符的总数≤1000。
 * 对于 100% 的数据，0≤表达式中加法运算符和乘法运算符的总数≤100000。
 * --------------------------------------------------------
 * @author: Junhao Wang
 * @date: 6/1/2021
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
void solve() {
    //读入中缀表达式
    getline(cin, s);
    //将中缀表达式转换为后缀表达式
    stack<char> stk;
    string ans;
    ll len = s.length();
    for (ll i = 0; i < len; i++) {
        if (s[i] == ' ') continue;//跳过空格
        if (s[i] == '+' || s[i] == '-') {
            while (!stk.empty() && stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        } else if (s[i] == '*' || s[i] == '/') {
            while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                ans += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        } else if (s[i] == '(') {
            stk.push(s[i]);
        } else if (s[i] == ')') {
            while (!stk.empty() && stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (s[i] >= '0' && s[i] <= '9') {
                ans += s[i];
                i++;
            }
            ans += ' ';
            i--;
        }
    }
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    //计算后缀表达式的值
    stack<ll> stk2;
    len = ans.length();
    for (ll i = 0; i < len; i++) {
        if (ans[i] == ' ') continue;
        if (ans[i] == '+' || ans[i] == '-' || ans[i] == '*' || ans[i] == '/') {
            ll a = stk2.top();
            stk2.pop();
            ll b = stk2.top();
            stk2.pop();
            if (ans[i] == '+') stk2.push((a + b) % 10000);//注意取模
            else if (ans[i] == '-') stk2.push((b - a) % 10000);//注意取模
            else if (ans[i] == '*') stk2.push((a * b) % 10000);//注意取模
            else stk2.push((b / a) % 10000);//注意取模
        } else {
            ll temp = 0;
            while (ans[i] >= '0' && ans[i] <= '9') {
                temp = temp * 10 + ans[i] - '0';
                i++;
            }
            stk2.push(temp);
            i--;
        }
    }
    cout << stk2.top();//输出结果
}
int main() {
    solve();
    return 0;
}