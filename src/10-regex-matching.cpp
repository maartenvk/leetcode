#include <iostream>
#include <string_view>

class Solution {
    char const* text;
    char const* pattern;

    int text_size;
    int pattern_size;

    bool** memo;
    bool** is_set;

    bool in_bounds(int i, int j) {
        return i < text_size + 1 && j < pattern_size + 1;
    }

    bool dp(int i, int j) {
        if (!in_bounds(i, j)) [[unlikely]] {
            return false;
        }

        if (is_set[i][j]) {
            return memo[i][j];
        }

        is_set[i][j] = true;

        if (j == pattern_size) {
            return memo[i][j] = i == text_size;
        }

        bool first_match = (i < text_size && pattern[j] == text[i]) || pattern[j] == '.';
        if (j + 1 < pattern_size && pattern[j + 1] == '*') {
            return memo[i][j] = dp(i, j + 2) || (first_match && dp(i + 1, j));
        }

        return memo[i][j] = first_match && dp(i + 1, j + 1);
    }

public:
    bool isMatch(std::string_view s, std::string_view p) {
        text = s.data();
        pattern = p.data();

        text_size = int(s.size());
        pattern_size = int(p.size());

        memo = new bool*[text_size + 1];
        is_set = new bool*[text_size + 1];
        for (int i = 0; i < text_size + 1; i++) {
            memo[i] = new bool[pattern_size + 1];
            is_set[i] = new bool[pattern_size + 1];
            for (int j = 0; j < pattern_size + 1; j++) {
                is_set[i][j] = false;
            }
        }

        return dp(0, 0);
    }
};

int main() {
    Solution s;
    auto result = s.isMatch("ab", ".*c");

    std::cout << "Result: " << (result & 0b1) << std::endl;
    return 0;
}
