/*************************************************************************
	> File Name: 2sum.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Mon 11 Jan 2021 09:30:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, target, num[100005];

int main()
{
    cin >> n >> target;
    for (int i  = 0; i < n; i++) {
        cin >> num[i];
    }
    
    int l = 0, r = n - 1;
    while (l < r) {
        int value = num[l] + num[r];
        if (value > target) {
            r--;
        } else if (value < target) {
            l++;
        } else {
            cout << l << "\t" << r << endl;
            cout << num[l] << "\t" << num[r] << endl;
            return 0;
        } 
    }

    /*
    for (int i = 0; i < n - 1; i++) {
        int l = i + 1, r = n - 1, t = target - num[i];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] == t) {
                cout << i << " \t" << mid << endl;
                cout << num[i] <<  " \t" << num[mid]<< endl;
                return 0;
            } else if (num[mid] > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

    }
    */
    cout << "not found" << endl;

}
