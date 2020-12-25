#include <iostream>

using namespace std;

int main()
{
/*
	int sum = 0;
	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	cout << sum << endl;
*/
	int a3 = (3 + 999)*333/2;
	int a5 = (5 + 995)*199/2;
	int a15 = (15 + 990)*66/2;
	int sum = a3 + a5 - a15;
	cout << sum << endl;

}
