//
// Created by Junhao on 2023/6/1.
//
#include <bits/stdc++.h>//包含所有头文件

#define ll long long//定义ll为long long
using namespace std;//使用命名空间std
struct ry {//定义一个结构体
    ll v;//定义一个ll类型的变量v
    double c;//定义一个double类型的变量c
};//结构体结束
stack<ry> vis;//定义一个结构体类型的栈
//定义一个主函数
int main() {//主函数开始
    ios::sync_with_stdio(0);//关闭cin和stdin的同步，加快cin的速度
    char p;//定义一个字符变量p
    ll v0, v1, v2, n;//定义ll类型的变量v0,v1,v2,n
    double c0, c1, c2;//定义double类型的变量c0,c1,c2
    cin >> v0 >> c0 >> n;//输入v0,c0,n
    v2 = v0;//v2=v0
    c2 = c0;//c2=c0
    //循环n次
    for (ll i = 0; i < n; i++) {//循环开始
        cin >> p;//输入p
        if (p == 'P') {//如果p=='P'
            cin >> v1 >> c1;//输入v1,c1
            vis.push({v1, c1});//将v1,c1压入栈
            c0 = (v0 * c0 + v1 * c1) / (v0 + v1);//计算c0
            c0 = c0;//c0=c0
            v0 = v0 + v1;//v0=v0+v1
//            printf("%d %.5lf\n", v0, c0);
            cout << fixed << setprecision(5) << v0 << " " << c0 << endl;//输出v0,c0
        }
            //如果p=='C'
        else {
            //如果栈为空
            if (vis.empty()) {
//                printf("%d %.5lf\n", v2, c2);
                cout << fixed << setprecision(5) << v2 << " " << c2 << endl;//输出v2,c2
                continue;//跳过本次循环
            }
            //如果栈不为空
            ry tmp = vis.top();//定义一个结构体类型的变量tmp，将栈顶元素赋值给tmp
            vis.pop();//弹出栈顶元素
            v1 = tmp.v;//v1=tmp.v
            c1 = tmp.c;//c1=tmp.c
            c0 = (v0 * c0 - v1 * c1) / (v0 - v1);//计算c0
            v0 = v0 - v1;//v0=v0-v1
//            printf("%d %.5lf\n", v0, c0);
            cout << fixed << setprecision(5) << v0 << " " << c0 << endl;//输出v0,c0
        }//else结束
    }//循环结束
    return 0;//返回0
}

