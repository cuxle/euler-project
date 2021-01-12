/*************************************************************************
	> File Name: yanghui.cpp
	> Author: cuxle
	> Mail: cuixiaolele@gmail.com
	> Created Time: Tue 12 Jan 2021 09:42:09 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>> ans;

void printVector(vector<vector<int>> &vec)
{
    if (vec.size() == 0) return;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> n;
    if (n == 0) {
        
    } else {
        ans.push_back({1});
        for (int i = 1;  i < n; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j++) {
                tmp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            } 
            tmp.push_back(1);
            ans.push_back(tmp);
        }

    }
    printVector(ans);
    return 0;
}
