#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string longest{s};

        for (size_t size = 0; size <= s.size(); size++) {
            for (size_t i = 0; i <= (s.size() - size); i++) {
                auto slice = s.substr(i, size);

                if (is_palindrome(slice)) {
                    longest = std::string{slice};
                }
            }
        }

        return longest;
    }

    bool is_palindrome(std::string const& s) {
        static std::unordered_map<std::string, bool> cache;

        if (s.size() < 2) {
            return true;
        }

        if (cache.count(s)) {
            return cache[s];
        }

        if (s[0] != s[s.size() - 1]) {
            return cache[s] = false;
        }

        return cache[s] = is_palindrome(s.substr(1, s.size() - 2));
    }
};

int main() {
    Solution s;
    auto result = s.longestPalindrome("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
