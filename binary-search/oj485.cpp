#include <iostream>

using namespace std;

int num[105], n;

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    int avg = sum / n, stp = 0;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] != avg) {
            stp++;
            num[i + 1] -= (avg - num[i]);
        }
    }
    cout << stp << endl;
    return 0;
}
