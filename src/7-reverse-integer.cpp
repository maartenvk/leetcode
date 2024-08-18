#include <iostream>
#include <limits>

class Solution {
public:
    int32_t reverse(int32_t x) {
        int32_t other {0};
        constexpr int32_t upper_limit{std::numeric_limits<int32_t>::max() / 10};
        constexpr int32_t lower_limit{std::numeric_limits<int32_t>::min() / 10};

        while (x != 0) {
            if (other < lower_limit || other > upper_limit) [[unlikely]] {
                return 0;
            }

            other *= 10;
            other += x % 10;
            x /= 10;
        }

        return other;
    }
};

int main() {
    Solution s;
    int32_t result = s.reverse(1534236469);
   // result = s.reverse(321);

    std::cout << "Result: " << result << std::endl;
    return 0;
}
