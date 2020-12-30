#include <iostream>

using namespace std;

long long num[1005][1005], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            num[i][j] += max(num[i+1][j], num[i+1][j+1]);
        }
    }
    cout << num[1][1] << endl;

    return 0;
}
