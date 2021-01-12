/*************************************************************************
	> File Name: oj518.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 01:13:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[10005];

int main()
{
    int n = 0;
    cin >> n;
    int day = 1, index = 1;
    while (index < 10005) {
            for (int i = 1; i <= day; i++) {
                num[index] = day;
                num[index] += num[index - 1];
                index++;  
            }
        day++;
    }
    cout << num[n] << endl;
}
