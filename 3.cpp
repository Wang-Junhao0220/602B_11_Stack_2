//
// Created by Junhao on 2023/6/1.
//
/*
 * 题目描述：
 * 输入一个十进制数，将它转换为 k 进制数。 要点：除 k 取余，倒序排列。
 * k 进制数位用’0’~’9’, ’A’, ’B’, ’C’, ’D’, ’E’, ’F’来表示。
 * 要求：用栈模拟递归过程。
 * --------------------------------------------------------
 * 输入格式：
 * 一行，两个正整数 n, k，分别表示需要转换的十进制数，以及转换后的进制。
 * 其中，0<=n<=2^31-1, 2<=k<=16。
 * 输出格式：
 * 一行，表示转换后的 k 进制数。
 * 输入样例：
 * 125 16
 * 输出样例：
 * 7D
 * --------------------------------------------------------
 * @author: Junhao Wang
 * @date: 6/1/2021
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll num,jin_zhi;//num为十进制数，jin_zhi为进制数
void solve() {
    cin>>num>>jin_zhi;
    stack<char> s;
    while(num) {
        int temp=num%jin_zhi;
        if(temp<10) s.push(temp+'0');
        else s.push(temp-10+'A');
        num/=jin_zhi;
    }//将余数入栈
    while(!s.empty()) {
        cout<<s.top();
        s.pop();
    }//倒序输出
}
int main() {
    solve();//调用函数
    return 0;
}