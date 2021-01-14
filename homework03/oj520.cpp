/*************************************************************************
	> File Name: oj520.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 01:46:50 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

long long a, k, n, sum1, sum2;
// sum1 (1 ~ k - 1)
// sum2 (k + 1 ~ n)

int main()
{
    cin >> a;
    k = a, n = k + 1;
    sum1 = (1 + a - 1) * (a - 1) / 2;
    sum2 = n;
    while (sum1 != sum2) {
        if (sum1 > sum2) {
            n++;
            sum2 += n;
        } else {
            sum1 += k;
            sum2 -= (k + 1);
            k++;
        }

    }
    cout << k << " " << n << endl;
    return 0;
}

