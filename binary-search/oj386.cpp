#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	int id, num;
};

node gua[100005];
int n, m;

bool cmp(const node &n1, const node &n2)
{
	return n1.num < n2.num;
}


int binary_search(node *guaa, int &target)
{
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (guaa[mid].num == target) {
			return gua[mid].id;
		} else if (guaa[mid].num > target) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return 0;
}

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &gua[i].num);
		gua[i].id = i + 1;
	}

	sort(gua, gua + n, cmp);

	for (int i = 0; i < m; i++) {
		int eatNums;
		scanf("%d", &eatNums);
		printf("%d\n", binary_search(gua, eatNums));
	}
	
	return 0;
}
