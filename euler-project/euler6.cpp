#include <iostream>

using namespace std;

int main()
{
	int sumSquare = 0;
	int squareSum = 0;
	for (int i = 1; i <= 100; i++) {
		sumSquare += i * i;
		squareSum += i;
	}
	squareSum = squareSum * squareSum;
	cout << squareSum - sumSquare << endl;
}
