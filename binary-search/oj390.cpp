#include <iostream>

using namespace std;

int n, m, maxl;
int num[100005];

int func(int base)
{
	int seg = 0;
	for (int i = 0; i < n; i++) {
		seg += num[i] / base;
	}
	return seg;
}

int search(int target)
{
	int l = 1, r = maxl;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		int seg = func(mid);
		if (seg >= target) {
			l = mid;
		} else if (seg < target) {
			r = mid - 1;
		}
	}
	return l;
}


int main() 
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		maxl = max(maxl, num[i]);
	}

	cout << search(m) << endl;

	return 0;
}
