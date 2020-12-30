#include <iostream>
using namespace std;

//int num[1000000];
//
//int main() {
//	num[1] = 1;
//	num[2] = 2;
//	int i = 0;
//	for (i = 3; 1; i++) {
//		num[i] = num[i - 1] + num[i - 2];
//		if (num[i] >= 4000000) {
//			break;
//		}
//	}
//
//	int sum = 0;
//	for (int j = 1; j <= i; j++) {
//		if (num[j] % 2 == 0) {
//			sum += num[j];
//		}
//	} 
//	cout << sum << endl;
//
//	return 0;
//}
int main()
{
	int a = 1, b = 2, ans = 0;
	while (b <= 4000000) {
		if (b % 2 == 0) {
			ans += b;
		}
		b = a + b;
		a = b - a;
	}
	cout << ans << endl;
}
