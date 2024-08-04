#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> seen;

        size_t start{};
        int record{}, count{};
        for (size_t i = 0; i < s.length(); i++) {
            char c = s[i];
            if (seen.find(c) == seen.end()) {
                seen.insert(c);
                count++;
            } else {
                record = std::max(record, count);
                seen.erase(seen.find(s[start]));

                count--;
                start++;
                i--;
            }
        }

        record = std::max(record, count);
        return record;
    }
};

int main() {
    Solution s;
    auto result = s.lengthOfLongestSubstring("abcabcbb");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
