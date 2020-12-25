#include <iostream>

using namespace std;

int isPalindrogmic(int x) {
	int rev = 0;
	int raw = x;
	while (x) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev == raw;
} 

int main() {
	int ans = 0;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			if (isPalindrogmic(i*j)) {
				ans = max(ans, i*j);
			}
		}
	}
	cout << ans << endl;
}
