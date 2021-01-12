/*************************************************************************
	> File Name: oj502.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 10:26:27 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>

using namespace std;

int num[30005], w, n;

int main()
{
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);
    int l = 0, r = n - 1, cnt = 0;
    while (l <= r) {
        if (l == r) {
            cnt++;
            break;
        }
        if (num[l] + num[r] <= w) {
            l++;
            r--;
            cnt++;
        }
        if (num[l] + num[r] > w) {
            cnt++;
            r--;
        }
    }
    cout << cnt << endl;
    return 0;
}
