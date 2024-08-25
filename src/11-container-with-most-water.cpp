#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) noexcept {
        int const* const height_nonvec = height.data();
        int greatest_volume {0};

        int i {0}, j {int(height.size()) - 1};
        int a {height_nonvec[i]}, b {height_nonvec[j]};
        while (j > i) {
            int calculated_volume {j - i};

            if (a < b) {
                calculated_volume *= a;
                a = height_nonvec[++i];
            } else {
                calculated_volume *= b;
                b = height_nonvec[--j];
            }

            if (calculated_volume > greatest_volume) {
                greatest_volume = calculated_volume;
            }
        }

        return greatest_volume;
    }
};

int main() {
    Solution s;

    std::vector<int> vec {1,8,6,2,5,4,8,3,7};
    auto result = s.maxArea(vec);

    std::cout << "Result: " << result << std::endl;
    return 0;
}