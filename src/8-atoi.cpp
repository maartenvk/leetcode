#include <iostream>
#include <limits>

class Solution {
public:
    int myAtoi(std::string s) {
        int64_t output {0};

        bool has_read {false};
        bool is_signed {false};
        for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
            if (!has_read) {
                if (*it == ' ') {
                    continue;
                }

                if (*it == '-') {
                    is_signed = true;
                    has_read = true;
                    continue;
                }

                if (*it == '+') {
                    has_read = true;
                    continue;
                }
            }
            
            if (*it < '0' || *it > '9') {
                break;
            }

            has_read = true;

            int digit = (*it) - '0';
            output *= 10;
            output += digit;
            if (output > std::numeric_limits<int32_t>::max()) {
                if (is_signed) {
                    return std::numeric_limits<int32_t>::min();
                } else {
                    return std::numeric_limits<int32_t>::max();
                }
            }
        }

        if (is_signed) {
            return 0 - output;
        }

        return output;
    }
};

int main() {
    Solution s;
    auto result = s.myAtoi("0-1");

    std::cout << "Result: " << result << std::endl;
    return 0;
}
