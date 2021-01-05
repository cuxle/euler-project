/*************************************************************************
	> File Name: oj392.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Sat 02 Jan 2021 02:18:51 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

long long num[100005], A, B, dis_min = (1 << 31 -1), dis_max;

long long func(long long len)
{
    int lastIndex = 0, cnt = 1;
    for (int i = 1; i < A; i++) {
        long long dis = num[i] - num[lastIndex];
        if (dis < len) {
            continue;
        } else if (dis >= len){
            lastIndex = i;
            cnt++;
        }

    }        
    return cnt;
}

int main() 
{
    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        cin >> num[i];
    }

    sort(num, num+A);

    for (int i = 1; i < A; i++) {
        dis_min = min(dis_min, num[i] - num[i - 1]);
    }

    dis_max = num[A - 1] - num[0];

    //cout << "min:" << dis_min << " " << "max:" << dis_max << endl;

    long long l = dis_min, r = dis_max;
    while (l != r) {
        long long mid = (l + r + 1) / 2;
        long long seg = func(mid);
        if (seg < B) {
            r = mid - 1;
        } else {
            l = mid;
        }

    }
    cout << l << endl;
    return 0;
}
