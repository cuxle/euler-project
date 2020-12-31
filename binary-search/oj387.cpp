#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
struct node {
	int id, num;
};

node repo[100005];
bool cmp(const node &n1, const node &n2)
{
	return n1.num < n2.num;
}
// 000000 1 1 1 1
int binary_search(int target)
{
	int l = 0, r = n - 1;
	if (target > repo[n - 1].num) return 0;
	while (l != r) {
		int mid = (l + r) / 2;
		if (repo[mid].num < target) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return repo[l].id;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &repo[i].num);
		repo[i].id = i + 1;
	}

	sort(repo, repo+n, cmp);
	
	int eatNums = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &eatNums);
		printf("%d\n", binary_search(eatNums));;
	}
	return 0;
}
