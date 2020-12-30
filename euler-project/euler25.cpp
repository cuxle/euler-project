#include <iostream>

using namespace std;


int num[2][1100] = {{1, 1}, {1, 1}};
void print(int *numm) {
	static int index = 1;
	cout << "fib index:" << index++ << " ";
	for (int i = 0; i < 1100; i++) {
		cout << numm[i];
	}
	cout << endl;
}
int func(int *n1, int *n2)
{
//	print(n1);
//	print(n2);
	
	n1[0] = n2[0];
	for (int i = 1; i <= n1[0]; i++) {
		n1[i] += n2[i];
		if (n1[i] > 9) {
			n1[i + 1]++;
			n1[i] %= 10;
			if (i == n1[0]) {
				n1[0]++;
			}
		}
	}
	return n1[0] >= 1000;
}

int main(){
	int a = 0, b = 1;
	int i = 2;
	while (1) {
		print(num[a]);
		i++;
		if (func(num[a], num[b])) {			
			cout << "i:" << i << endl; 
			break;
		}
		swap(a, b);
	}
	cout << i << endl;

}
