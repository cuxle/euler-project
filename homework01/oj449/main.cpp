#include <iostream>

using namespace std;

int num[25][25], n;
int main()
{
    num[1][1] = 1;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] = num[i-1][j-1] + num[i-1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j != 1) cout << " ";
            cout << num[i][j];
        }
        cout << endl;
    }

    return 0;
}
