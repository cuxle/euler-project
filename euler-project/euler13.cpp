#include <iostream>
#include <cstring>
using namespace std;

int num[60];
int main() 
{
	
	for (int i = 0; i < 100; i++) {
		char str[51];
		memset(str, 0, sizeof(str));
		cin >> str;
		int j = 0;
		for (int i = 49; i >= 0; i --) {
			int dec = str[i] - '0';
			num[j] += dec;
			j++;
			cout << i << " "  << str[i] << endl;
		}
		j = 0;
		int next = 0;
		while (j < 60) {
			num[j] += next;
			int left = 0;
			if (num[j] >= 10) {
				next = num[j] / 10;
				left = num[j] % 10;
				num[j] = left;
			} else {
				next = 0;
			}
			j++;
		}
		cout << "i:" << i << " ";
		for (int i = 59; i > 0; i--) {
			cout << num[i];
		}
		cout << endl;

	}
	cout << "result:";
	for (int i = 59; i > 0; i--) {
		cout << num[i];
	}
	cout << endl;
	return 0;
}
