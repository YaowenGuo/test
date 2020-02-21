//
// Created by Yaowen on 2019-04-28.
//

#include <vector>



class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> result;

        if (nums != null & nums.size() > 1) {
            Quicks_Sort(nums);
            int start = 0;
            int end = nums.size() - 1;
            while (start < end && (nums[start] + nums[end] != target)) {
                if ((nums[start] + nums[end] < target) {
                    start++;
                } else {
                    end--;
                };

            };

            if (start < end) {
                result.push_back(start);
                result.push_back(end);
            }

        }
        return result;
    }
};
