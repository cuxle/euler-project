/*************************************************************************
	> File Name: oj506.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 10:43:52 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>

using namespace std;

struct node {
    int index;
    int value;
};

int n;
node num[35];
bool comp(const node &n1, const node &n2)
{
    return n1.value < n2.value;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i].value;
        num[i].index = i + 1;
    }
    sort(num, num + n, comp);

    double all = 0;
    int now = 0;
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            cout << " ";
        }
        if (i != n - 1) {
            now += num[i].value;
            all += now;
        }
        cout << num[i].index;
    }
    cout << endl;
    printf("%.2f\n", all / n);
}
