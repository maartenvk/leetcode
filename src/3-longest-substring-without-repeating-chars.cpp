#include <iostream>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::string record;
        std::unordered_set<char> seen;

        size_t i{0};
        for (size_t index = 0; index < s.length(); index++) {
            seen.clear();
            for (; (i + index) < s.length(); i++) {
                if (seen.find(s[i + index]) != seen.end()) {
                    if (i > record.size()) {
                        record = s.substr(index, i);
                    }

                    i = 0;
                    break;
                }

                seen.insert(s[i + index]);
            }

            if (i > 0 && i > record.size()) {
                record = s.substr(index, i);
            }
        }

        return record.size();
    }
};

int main() {
    Solution s;
    auto result = s.lengthOfLongestSubstring("aab");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
