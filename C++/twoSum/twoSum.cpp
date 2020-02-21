#include <iostream>
//
// Created by Yaowen on 2019-04-28.
//
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;




class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> result;

        if (!nums.empty() && nums.size() > 1) {
            vector<pair<int, int>> vectorMap;
            for(int i = 0; i < nums.size(); i++) {
                vectorMap.emplace_back(nums[i], i);
            }

            sort(nums.begin(), nums.end());
            int start = 0;
            long end = vectorMap.size() - 1;
            while (start < end && (vectorMap[start].first + vectorMap[end].first != target)) {
                if (vectorMap[start].first + vectorMap[end].first < target) {
                    start++;
                } else {
                    end--;
                }

            }

            if (start < end) {
                result.push_back(vectorMap[start].second);
                result.push_back(vectorMap[end].second);
            }

        }

        return result;
    }
};




int main() {

    vector<int> v = { 3, 2, 4};

    
    Solution solution;
    vector<int> result = solution.twoSum(v, 6);
    cout << "out: [";
    for (int i = 0; i < v.size(); i++) {
        cout << result[i] << ", ";
    }
    cout << "]" << endl;


    return 0;
}
