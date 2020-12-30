#include <iostream>

using namespace std;

long long chains(long long num)
{
	
	if (num == 1) {
		return 1;
	}
	if (num % 2 == 0) {
		return 1 + chains(num / 2);
	} else {
		return 1 + chains(3 * num + 1);
	}

//	long long ch = 0;
//	while (1) {
//		if (num == 1) {
//			return ++ch;
//		} else if (num % 2 == 0) {
//			ch++;
//			num /= 2;
//		} else if (num % 2 != 0) {
//			ch++;
//			num = 3 * num + 1;
//		}
//
//	}
//	return -1;
}
int main() {
	long long ans = 0, index;
	for (int i = 1; i < 1000000; i++) {
		long long now = chains(i);
		if (now > ans) {
			ans = now;
			index = i;
		}
	}
	cout << ans <<" " <<  index << endl;
	return 0;
}
