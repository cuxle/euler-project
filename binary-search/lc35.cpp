#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums.at(0)) return 0;
        if (target > nums.at(nums.size() - 1)) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l != r) {
            int mid = (l + r) / 2;
            if (nums.at(mid) < target) {
                l = mid + 1;
            } else {
                r = mid;
            }

        }
        return l;
    }
};
