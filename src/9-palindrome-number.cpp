#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) [[unlikely]] {
            return false;
        }

        if (x < 10) [[unlikely]] {
            return true;
        }
        
        // get leftmost digit index
        int copy {x};
        int il {-1}; // index left
        while (copy) {
            copy /= 10;
            il++;
        }

        int ir {0};
        while (il > ir) {
            int a {x / int(std::pow(10., (float)il)) % 10};
            int b {x / int(std::pow(10., (float)ir)) % 10};

            if (a != b) {
                return false;
            }
            
            il--;
            ir++;
        }

        return true;
    }
};

int main() {
    Solution s;
    auto result = s.isPalindrome(1221);
    
    std::cout << "Result: " << result << std::endl;
    return 0;
}
