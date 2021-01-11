/*************************************************************************
	> File Name: 2sum_hash.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Mon 11 Jan 2021 10:18:43 PM CST
 ************************************************************************/

#include<iostream>
#include <unordered_map>

using namespace std;

int n, target, num[100005];

unordered_map<int, int> m;

int main()
{
    cin >> n >> target;

    for (int i = 0; i < n; i ++) {
        cin >> num[i];
        m[num[i]] = i;    
    }

    for (int i = 0; i < n; i++) {
        if (m.count(target - num[i]) > 0) {
            cout << i << "\t" << m[target - num[i]] << endl;
            cout << num[i] << "\t" << num[target - num[i]] << endl;
            return 0;
        } 

    }
    cout << "not found" << endl;
    return 0;
}
