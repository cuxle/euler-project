/*************************************************************************
	> File Name: leetcode38.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Mon 11 Jan 2021 10:45:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

string ans[35] = {"", "1"};
int num = 1;

string countAndSay(int n) 
{
    if (n <= num) {
        return ans[n];
    }    

    for (int i = num + 1; i <= n; i++) {
        int cnt = 1;
        char lastChar = ans[i - 1].at(0);
        int index = 1;
        string aim;
        while (index < ans[i - 1].size()) {
            if (ans[i - 1].at(index) != lastChar) {
                aim += cnt + '0';
                aim += lastChar;
                cnt = 1;
                lastChar = ans[i - 1].at(index);
            } else {
                cnt++;
            }
            index++;
        }
        aim += cnt + '0';
        aim += lastChar;
        ans[i] = aim;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
}
