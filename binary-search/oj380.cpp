#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	int id;
	string num;
};
int n;
node creature[105];

bool cmp(const node &n1, const node &n2) {
	if (n1.num.size() == n2.num.size()) {
		return n1.num > n2.num;
	}
	return n1.num.size() > n2.num.size();
}

//bool cmp(const node &n1, const node &n2) 
//{
//
//	if (n1.num.length() > n2.num.length()) return true;
//	if (n1.num.length() < n2.num.length()) return false;
//	if (n1.num.length() == n2.num.length()) {
//		for (int i = 0; i < n2.num.length(); i++) {
//			if (n1.num.at(i) > n2.num.at(i)) {
//				return true;
//			} else if (n1.num.at(i) < n2.num.at(i)) {
//				return false;
//			}
//		}
//	}
//	return false;
//}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> creature[i].num;
		creature[i].id = i + 1;
	}

	sort(creature, creature + n, cmp);

//	for (int i = 0; i < n; i++) {
//		cout << "i:" << creature[i].id << " " << creature[i].num << endl; 
//	}
	cout << creature[0].id << endl;
	cout << creature[0].num << endl;
}
