#include <iostream>
#include <cstring>
using namespace std;

char str1[1005], str2[1005];
int num1[1005], num2[1005], ans[1005];

int main() 
{
	cin >> str1 >> str2;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int j = 1;
	for (int i = len1 - 1; i >= 0; i--) {
		num1[j] = str1[i] - '0';
		j++;
	}
	j = 1;
	for (int i = len2 - 1; i >= 0; i--) {
		num2[j] = str2[i] - '0';
		j++;
	}

	num1[0] = len1;
	num2[0] = len2;
	cout << "len1: "<< len1 << endl;
	cout << "len2:" << len2 << endl;
	cout << "str1:" << str1 << endl;
	cout << "str2: " << str2 << endl;
	ans[0] = len1 + len2 - 1;
	for (int i = 1; i <= num1[0]; i++) {
		for (int j = 1; j <= num2[0]; j++) {
			ans[i + j - 1] += num1[i] * num2[j];
		}
	}

	for (int i = 1; i <= ans[0]; i++) {
		if (ans[i] > 9) {
			ans[i + 1] += ans[i] / 10;
			ans[i] = ans[i] % 10;
			if (i == ans[0]) {
				ans[0]++;
			}
		}
	}
	
	for (int i = ans[0]; i >= 1; i--) {
		cout << ans[i];
	}
	cout << endl;
}
