#include <iostream>
#include <map>
#include <vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, std::vector<int>> m;
        for(int i=0; i<nums.size(); ++i){
            m[nums[i]].push_back(i);
        }
        
        for(int i=0; i<nums.size(); ++i){
            for(const auto& el : m[target-nums[i]]){
                if(i != el){
                    return std::vector<int>{i, el};
                }
            }
        }
    }
};

void printVector(const std::vector<int>& v){
	for(const auto& el : v){
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main(){
	std::vector<int> v {2,7,11,15};
	int target = 9;

	Solution s;
	const auto result = s.twoSum(v, target);
	printVector(result);

	return 0;
}