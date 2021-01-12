/*************************************************************************
	> File Name: oj600.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Mon 11 Jan 2021 10:03:41 PM CST
 ************************************************************************/

#include<iostream>
#include <cstdio>

using namespace std;

int n, m, target, num[3005][3005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    scanf("%d", &target);
    int x = n, y = 1;
    while (x >= 1 && y <= m) {
        if (num[x][y] == target) {
            printf("%d %d\n", x, y);
            return 0;
        }
        if (num[x][y] > target) {
            x--;
        } else {
            y++;
        }
    }
    printf("not found");
    return 0;
}
