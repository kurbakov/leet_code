class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    int i = nums.size()-2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        --i;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        std::swap(nums[i], nums[j]);
    }
    std::reverse(nums.begin() + i + 1, nums.end());
  }
};
