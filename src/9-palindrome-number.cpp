#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x > 10) [[unlikely]] {
            return false;
        }
        
        int copy {x};
        int64_t reversed {0};

        while (x) {
            reversed *= 10;
            reversed += x % 10;
            x /= 10;
        }

        return reversed == copy;
    }
};

int main() {
    Solution s;
    auto result = s.isPalindrome(1221);
    
    std::cout << "Result: " << result << std::endl;
    return 0;
}
