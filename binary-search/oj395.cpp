#include <iostream>

using namespace std;

int m, k, ans[505][2], pages[505];

int func(int mmax)
{
    int sum = 0, s = 0;
    for (int i = 0; i < m; i++) {
        if (sum + pages[i] == mmax) {
            sum = 0;
            s++;
        } else if (sum + pages[i] > mmax) {
            sum = pages[i];
            s++;
        } else {
            sum += pages[i];
        }
    }
    if (sum != 0) {
        s++;
    }
    return s;
}

int main()
{
    cin >> m >> k;
    int totalPages = 0;
    for (int i = 0; i < m; i++) {
        cin >> pages[i];
        totalPages += pages[i];
    }

//    cout << "m:" << m << " k:" << k << endl;
//    for (int i = 0; i < m; i++) {
//        cout << pages[i] << endl;
//    }

    int l = 0, r = totalPages;
    while (l != r) {
        int mid = (l + r) / 2;
        int s = func(mid);
        if (s > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int sum = 0, last = m - 1, ansIndex = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (sum + pages[i] > l) {
            ans[ansIndex][1] = last+1;
            ans[ansIndex][0] = i + 1+1;
            ansIndex++;

            sum = pages[i];
            last = i;
        } else if (sum + pages[i] == l) {
            ans[ansIndex][1] = last+1;
            ans[ansIndex][0] = i+1;
            ansIndex++;

            sum = 0;
            last = i - 1;
        } else {
            sum += pages[i];
        }
    }
    if (sum != 0) {
        ans[ansIndex][1] = last+1;
        ans[ansIndex][0] = 0+1;
        ansIndex++;
    }

    for (int i = ansIndex - 1; i >= 0; i--) {
        cout <<ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
