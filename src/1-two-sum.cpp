#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, size_t> indices;

        for (auto it = nums.begin(); it != nums.end(); it++) {
            int query = target - *it;
            if (indices.find(query) != indices.end()) {
                size_t dist = std::distance(nums.begin(), it);
                if (indices[query] != dist) {
                    return {int(dist), int(indices[query])};
                }
            }

            indices[*it] = std::distance(nums.begin(), it);
        }

        return {};
    }
};


int main() {
    std::vector<int> nums {3, 2, 4};

    Solution s;
    auto ans = s.twoSum(nums, 6);
    if (ans.empty()) {
        std::cout << "No result\n";
    } else {
        std::cout << ans[0] << ", " << ans[1] << std::endl;
    }
}
