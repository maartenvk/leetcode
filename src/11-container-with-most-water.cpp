#include <iostream>
#include <vector>

class Solution {
public:
    __attribute__((always_inline)) int inline maxArea(std::vector<int> const& height) const noexcept {
        int const* const arr = height.data();
        int greatest_volume {0};

        int i {0}, j {int(height.size()) - 1};
        while (j > i) {
            int a {arr[i]}, b {arr[j]};
            int calculated_volume {j - i};

            bool comparison = (a < b);
            calculated_volume *= comparison * a + !comparison * b;
            i += comparison;
            j -= !comparison;

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