/*************************************************************************
	> File Name: oj513.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 11:42:27 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[100005], m;

bool func(int value)
{
    int mod;
    while (value > 0) {
        mod = value % 10;
        value = value / 10;
        if (mod == m) {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int real = 0;
    for (int i = 1; i <= n; i++) {
        bool isSkipped = func(i);
        if (isSkipped) {

        } else {
            real++;
        }
    }
    cout << real << endl;
    return 0;
}
