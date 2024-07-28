#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int a = 0; a < nums.size(); a++) {
            for (int b = 0; b < nums.size(); b++) {
                if (b == a)
                    continue;

                int c = nums[a] + nums[b];
                if (c == target) {
                    return {a, b};
                }
            }
        }

        return {0, 0};
    }
};

int main() {
    return 0;
}
