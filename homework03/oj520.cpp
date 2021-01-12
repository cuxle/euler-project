/*************************************************************************
	> File Name: oj520.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 01:46:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long num[10000000];

int main()
{
    int a;
    cin >> a;

    for (int i = 1; i < 10000000; i++) {
        num[i] = i;
        num[i] += num[i - 1];
    }    
    
    for (int k = a; k < 10000000; k++) {
        cout << "k:" << k << " " << num[k] << endl;
        for (int n = k + 2; 1; n++) {
            if (num[k] == (num[n] - num[k+1])) {
                cout << k + 1 << " " << n << endl;
                return 0;                
            } else if(num[k] > (num[n] - num[k+1])) {
                continue;
            } else {
                break;
            }
        }
    }
    return 0;
}
