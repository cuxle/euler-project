#include <iostream>
#include <algorithm>

using namespace std;
int m,n, pos[100005];

int func(int gap)
{
    int sum = 1, last = 0;
    for (int i = 1; i < m; i++) {
        if (pos[i] - pos[last] >= gap) {
            last = i;
            sum++;
        }
    }

    return sum;
}

int search()
{
    int l = 2, r = pos[m - 1] - pos[0];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int value = func(mid);
        if (value < n) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + m);

    int ans = search();
    cout << ans << endl;
    return 0;
}
