/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is 
closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = 99999999;
        int result = 0;
        std::sort(nums.begin(), nums.end());
        
        int sum, diff;
        std::size_t j, k;
        for(std::size_t i=0; i<nums.size(); ++i){
            j = i+1;
            k = nums.size()-1;
            
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                diff = std::abs(sum - target);

                if(diff == 0) return sum;

                if(diff < min) {
                    min = diff;
                    result = sum;
                }
                if (sum <= target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};
