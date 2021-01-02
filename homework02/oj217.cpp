/*************************************************************************
	> File Name: oj217.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Fri 01 Jan 2021 12:13:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main()
{
    int n, nums[105] = {0};
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums[temp]++;
    }

    int ans = 0;
    for (int i = 100; i >= 0; i--) {
        ans += nums[i];
        if (ans >= (n / 2 + n % 2)) {
            cout << i << " " << ans << endl;
            break;
        }

    } 
    return 0;

}
