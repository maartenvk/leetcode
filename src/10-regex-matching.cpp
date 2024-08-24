#include <iostream>
#include <string_view>

class Solution {
    size_t s_size, p_size;

    bool is_match(char const* const s, char const* const p, size_t s_idx = 0, size_t p_idx = 0) {
        if (p_idx >= p_size) [[unlikely]] { // exhausted pattern
            return s_idx >= s_size;
        }

        if (s_idx >= s_size) [[unlikely]] { // exhausted string before pattern
            // if continuously followed with letters and '*', it can still match
            if (p[p_idx] == '*') {
                p_idx++;
            }

            bool has_next;
            for (bool valid = p_idx < p_size; valid; valid = p_idx < p_size) {
                has_next = (p_idx + 1) < p_size;
                char next = has_next ? p[p_idx + 1] : '\0';

                if (has_next && next == '*') {
                    p_idx += 2;
                } else {
                    return false;
                }
            }

            return p[p_idx - 1] == '*';
        }

        char s_cur {s[s_idx]};
        char p_cur {p[p_idx]};

        if (s_cur == p_cur || p_cur == '.') [[likely]] {
            if (is_match(s, p, s_idx + 1, p_idx + 1)) {
                return true;
            }
        }

        if (p_cur == '*') {
            // is current string char valid?
            char p_prev {p[p_idx - 1]};
            if (p_prev == '.' || p_prev == s_cur) {
                // it matches. continue
                bool result = is_match(s, p, s_idx + 1, p_idx);
                if (result) {
                    return true;
                }

                // if it does not match, try skipping the current pattern char.
                result = is_match(s, p, s_idx + 1, p_idx + 1);
                if (result) {
                    return true;
                }

                // there was only one present and the next character was the repeating char.
                return is_match(s, p, s_idx, p_idx + 1);
            } else {
                // there was only one present, skip
                return is_match(s, p, s_idx, p_idx + 1);
            }
        }

        // with '*' if there are zero present, skip
        bool has_next = (p_idx + 1) < p_size;
        if (has_next && p[p_idx + 1] == '*') {
            return is_match(s, p, s_idx, p_idx + 2);
        }

        return false;
    }

public:
    bool isMatch(std::string_view s, std::string_view p) {
        s_size = s.size();
        p_size = p.size();

        return is_match(s.data(), p.data());
    }
};

int main() {
    Solution s;
    auto result = s.isMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*");

    std::cout << "Result: " << result << std::endl;
    return 0;
}
