/*************************************************************************
	> File Name: oj394.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Mon 04 Jan 2021 10:33:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int *num, int size, int distance)
{
    // give distance calculate the picks
    int lastIndex = 0, cnt = 0;
    for (int i = 1; i <= size; i++) {
        if (num[i] - num[lastIndex] < distance) {
            cnt ++; 
        } else {
            lastIndex = i;
        }
    }
    return cnt;
}

int main()
{
    int l1, n, m;
    int num[50005] = {0};
    cin >> l1 >> n >> m;
    for (int i = 1; i <= n ; i++) {
        cin >> num[i];
    }
    num[n + 1] = l1;
    int l = 0, r = num[n+1] - num[0];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int picks = func(num, n + 1, mid);
        if (picks > m) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l << endl;

}
