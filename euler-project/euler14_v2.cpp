#include <iostream>

using namespace std;

long long nums[10000000];

long long chains(long long num)
{
	if (num < 10000000 && nums[num]) {
		return nums[num] + 1;
	}
	long long t = 0;
	if (num == 1) {
		t = 1;
	} else if (num % 2 == 0) {
		t = 1 + chains(num / 2);
	} else {
		t = 1 + chains(3 * num + 1);
	}
	cout << "num:" << num << endl;
	if (num < 10000000) {
		nums[num] = t;
	}
	return t;
}

int main()
{
	int maxChains = 0, index = 0;
	for (int i = 1; i < 1000000; i++) {
		int chain = chains(i);
		if (maxChains < chain) {
			maxChains = chain;
			index = i;
		}
	}
	cout << index << endl;
}
