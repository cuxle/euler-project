#include <iostream>

using namespace std;

int n = 15, num[20][20];

int main()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j]; 
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			num[i][j] += max(num[i-1][j-1], num[i-1][j]);
			ans = max(ans, num[i][j]);
		}
	}
	cout << ans << endl;
	// 1074
	return 0;
}
