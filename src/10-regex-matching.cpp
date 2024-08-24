#include <iostream>
#include <string_view>

class Solution {
public:
    bool isMatch(std::string_view s, std::string_view p, size_t s_idx = 0, size_t p_idx = 0) {
        char p_prev {p_idx == 0 ? '\0' : p.at(p_idx - 1)};
        bool has_next = (p_idx + 1) < p.size();

        if (p_idx >= p.size()) { // exhausted pattern
            return s_idx >= s.size();
        }

        if (s_idx >= s.size()) { // exhausted string before pattern
            // if continuously followed with letters and '*', it can still match
            if (p.at(p_idx) == '*') {
                p_idx++;
            }

            for (bool valid = p_idx < p.size(); valid; valid = p_idx < p.size()) {
                has_next = (p_idx + 1) < p.size();
                char next = has_next ? p.at(p_idx + 1) : '\0';

                if (has_next && next == '*') {
                    p_idx += 2;
                } else {
                    return false;
                }
            }

            return p.at(p_idx - 1) == '*';
        }

        char s_cur {s.at(s_idx)};
        char p_cur {p.at(p_idx)};

        if (s_cur == p_cur || p_cur == '.') {
            if (isMatch(s, p, s_idx + 1, p_idx + 1)) {
                return true;
            }
        }

        if (p_cur == '*') {
            // is current string char valid?
            if (p_prev == '.' || p_prev == s_cur) {
                // it matches. continue
                bool result = isMatch(s, p, s_idx + 1, p_idx);
                if (result) {
                    return true;
                }

                // if it does not match, try skipping the current pattern char.
                result = isMatch(s, p, s_idx + 1, p_idx + 1);
                if (result) {
                    return true;
                }

                // there was only one present and the next character was the repeating char.
                return isMatch(s, p, s_idx, p_idx + 1);
            } else {
                // there was only one present, skip
                return isMatch(s, p, s_idx, p_idx + 1);
            }
        }

        // with '*' if there are zero present, skip
        if (has_next && p.at(p_idx + 1) == '*') {
            return isMatch(s, p, s_idx, p_idx + 2);
        }

        return false;
    }
};

int main() {
    Solution s;
    auto result = s.isMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*");

    std::cout << "Result: " << result << std::endl;
    return 0;
}
