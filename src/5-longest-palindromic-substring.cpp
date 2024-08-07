#include <iostream>

#include <string_view>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        const std::string_view sv(s);

        for (size_t size = sv.size(); size > 0; size--) {
            for (size_t i = 0; i <= (sv.size() - size); i++) {
                auto slice = sv.substr(i, size);

                if (is_palindrome(slice)) {
                    return std::string{slice};
                }
            }
        }

        return "";
    }

    bool is_palindrome(std::string_view s) {
        for (size_t i = 0, j = s.size() - 1; i < (s.size() / 2); i++, j--) {
            if (s.at(i) != s.at(j)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    auto result = s.longestPalindrome("dtgrtoxuybwyfskikukcqlvprfipgaygawcqnfhpxoifwgpnzjfdnhpgmsoqzlpsaxmeswlhzdxoxobxysgmpkhcylvqlzenzhzhnakctrliyyngrquiuvhpcrnccapuuwrrdufwwungaevzkvwbkcietiqsxpvaaowrteqgkvovcoqumgrlsxvouaqzwaylehybqchsgpzbkfugujrostopwhtgrnrggocprnxwsecmvofawkkpjvcchtxixjtrnngrzqpiwywmnbdnjwqpmnifdiwzpmabosrmzhgdwgcgidmubywsnshcgcrawjvfiuxzyzxsbpfhzpfkjqcpfyynlpshzqectcnltfimkukopjzzmlfkwlgbzftsddnxrjootpdhjehaafudkkffmcnimnfzzjjlggzvqozcumjyazchjkspdlmifvsciqzgcbehqvrwjkusapzzxyiwxlcwpzvdsyqcfnguoidiiekwcjdvbxjvgwgcjcmjwbizhhcgirebhsplioytrgjqwrpwdciaeizxssedsylptffwhnedriqozvfcnsmxmdxdtflwjvrvmyausnzlrgcchmyrgvazjqmvttabnhffoe");

    std::cout << "Result: " << result << std::endl;
    return 0;
}
