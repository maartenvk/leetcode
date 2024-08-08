#include <iostream>
#include <sstream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::ostringstream streams[numRows];

        if (numRows == 1) {
            return s;
        }

        int y {0};
        bool falling {true};

        for (char c : s) {
            streams[y] << c;

            if (falling) {
                y++;
            } else {
                y--;
            }

            if (y == numRows) {
                y -= 2;
                falling = false;
            }

            if (y <= 0) {
                y = 0;
                falling = true;
            }
        }

        for (int i = 1; i < numRows; i++) {
            streams[0] << streams[i].str();
        }

        return streams[0].str();
    }
};

int main() {
    Solution s;
    auto result = s.convert("PAYPALISHIRING", 3);
    std::cout << result << std::endl;
    return 0;
}
