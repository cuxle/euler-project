/*************************************************************************
	> File Name: oj388.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Fri 01 Jan 2021 11:43:16 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int m, n,  numm[100005], numn[100005];
int search(int target) 
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = ((long long)l + r) / 2;
        if (numn[mid] == target) {
            return numn[mid];
        } else if (numn[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }
    return -1;
}

void printArray(int *p, int size)
{
    for (int i = 0; i < size; i++) {
        if (i != 0) cout << " ";
        cout << *p++;
    }
    cout << endl;
}

int  main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> numm[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> numn[i];
    }

//    sort(numm, numm+m);

    sort(numn, numn+n);

//    printArray(numm, m);
//    printArray(numn, n);
    long long sum = 0;
    bool isfirst = true;
    for (int i = 0; i < m; i++) {
        int ans = search(numm[i]);
        if (ans != -1) {
            if (isfirst) {
                isfirst = false;
            } else if (!isfirst) {
                cout << " ";
            }
            cout << ans;
            sum += ans;
        }
    }
    cout << endl;
    cout << sum << endl;
}
