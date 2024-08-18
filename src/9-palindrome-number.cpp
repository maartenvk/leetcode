#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int copy {x};
        int64_t reversed {0};

        while (copy) {
            reversed *= 10;
            reversed += copy % 10;
            copy /= 10;
        }

        return reversed == x;
    }
};

int main() {
    Solution s;
    auto result = s.isPalindrome(1221);
    
    std::cout << "Result: " << result << std::endl;
    return 0;
}
