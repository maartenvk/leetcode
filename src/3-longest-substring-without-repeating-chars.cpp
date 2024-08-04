#include <iostream>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        size_t record{};
        std::unordered_set<char> seen;

        size_t i{0};
        for (size_t index = 0; index < s.length(); index++) {
            seen.clear();
            for (; (i + index) < s.length(); i++) {
                if (seen.find(s[i + index]) != seen.end()) {
                    record = std::max(i, record);
                    i = 0;
                    break;
                }

                seen.insert(s[i + index]);
            }

            record = std::max(i, record);
        }

        return record;
    }
};

int main() {
    Solution s;
    auto result = s.lengthOfLongestSubstring("aab");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
