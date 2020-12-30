#include <iostream>
#include <cstring>

using namespace std;

// calculate the mul of two didgits which has at most 100 width

char m1[105], m2[105];
int rm1[105], rm2[105], ans[300];

void printc(int *pn, int n)
{
    for (int i = 0; i <= n; i++) {
        cout << *pn++;
    }
    cout << endl;
}
int main()
{
    cin >> m1 >> m2;
    int lm1, lm2;
    lm1 = strlen(m1);
    lm2 = strlen(m2);
    rm1[0] = lm1;
    rm2[0] = lm2;

    for (int i = lm1 - 1, j = 1; i >= 0; i--, j++) {
        rm1[j] = m1[i] - '0';
    }

    for (int i = lm2 - 1, j = 1; i >= 0; i--, j++) {
        rm2[j] = m2[i] - '0';
    }

    ans[0] = lm1 + lm2 - 1;
    for (int i = 1; i <= lm2; i++) {
        for (int j = 1; j <= lm1; j++) {
            ans[i + j - 1] += rm1[j] * rm2[i];
        }
    }

    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
            if (i == ans[0]) {
                ans[0]++;
            }
        }
    }

    for (int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
