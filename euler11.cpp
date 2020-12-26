#include <iostream>

using namespace std;

int num[30][30];

// right up, right, right down, down
int dirx[4] = {-1, 0, 1, 1};
int diry[4] = {1, 1, 1, 0};

int main()
{
	for (int i = 5; i < 25; i++) {
		for (int j = 5; j < 25; j++) {
			cin >> num[i][j];
		}

	}
	int ans = 0;
	for (int i = 5; i < 25; i++) {
		for (int j = 5; j < 25; j++) {
			// 1. for 4 dirctions
			for (int k = 0; k < 4; k++) {
				int now = num[i][j];
				for (int l = 1; l < 4; l++) {
					// 2. for every dirction for items
					int x = i + dirx[k]*l;
					int y = j + diry[k]*l;
					now *= num[x][y];
				}
				ans = max(ans, now);
			}

		}
	}
	cout << ans << endl;
	return 0;
}
