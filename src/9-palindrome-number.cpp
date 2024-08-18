#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) [[unlikely]] {
            return false;
        }

        if (x < 10) [[unlikely]] {
            return true;
        }
        
        std::vector<int> scratch;
        while (x) {
            scratch.push_back(x % 10);
            x /= 10;
        }

        std::vector<int>::const_iterator itl, itr; // iterator left, right
        itl = scratch.begin();
        itr = scratch.end() - 1;

        while (itl < itr) {
            if (*itl != *itr) {
                return false;
            }

            itl++;
            itr--;
        }

        return true;
    }
};

int main() {
    Solution s;
    auto result = s.isPalindrome(10101);
    
    std::cout << "Result: " << result << std::endl;
    return 0;
}
