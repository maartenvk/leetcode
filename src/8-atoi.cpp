#include <iostream>
#include <limits>

class Solution {
public:
    int myAtoi(std::string s) {
        int32_t output {0};

        constexpr int32_t upper_limit{std::numeric_limits<int32_t>::max() / 10};

        bool has_read {false};
        bool is_signed {false};
        for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
            if (!has_read && *it == ' ') { // skip whitespace
                continue;
            }

            if (!has_read && *it == '-') { // if not started & is minus sign
                is_signed = true;
                has_read = true;
                continue;
            }

            if (!has_read && *it == '+') { // skip over plus sign
                has_read = true;
                continue;
            }
            
            if (*it < '0' || *it > '9') { // if not a digit
                break;
            }

            int digit = (*it) - '0';
            if (output > upper_limit) [[unlikely]] {
                if (is_signed) {
                    return std::numeric_limits<int32_t>::min();
                } else {
                    return std::numeric_limits<int32_t>::max();
                }
            }

            output *= 10;

            auto add_limit {std::numeric_limits<int32_t>::max() - digit};
            if (output > add_limit) [[unlikely]] {
                if (is_signed) {
                    return std::numeric_limits<int32_t>::min();
                } else {
                    return std::numeric_limits<int32_t>::max();
                }
            }

            output += digit;
            has_read = true;
        }

        if (is_signed) {
            return 0 - output;
        }

        return output;
    }
};

int main() {
    Solution s;
    auto result = s.myAtoi("words and 987");

    std::cout << "Result: " << result << std::endl;
    return 0;
}
