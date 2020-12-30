#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char m[105], n[105];
int rm[105], rn[105], ans[105];
int main()
{
    cin >> m >> n;
    int mlen = strlen(m);
    int nlen = strlen(n);

//    cout << m << " " << n << " " << mlen << " " << nlen << endl;
    int j = 0;

    rm[j++] = mlen;
    for (int i = mlen - 1; i >= 0; i--) {
        rm[j++] = m[i] - '0';
    }

    j = 0;
    rn[j++] = nlen;
    for (int i = nlen - 1; i >= 0; i--) {
        rn[j++] = n[i] - '0';
    }

    int longer = mlen > nlen ? mlen : nlen;
    j = 0;
    ans[j++] = longer;
    for (; j <= ans[0]; j++) {
        ans[j] += (rm[j] + rn[j]);
        if (ans[j] > 9) {
            ans[j + 1] += ans[j] / 10;
            ans[j] = ans[j] % 10;
            if (j == ans[0]) {
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
