#include <cstddef>
#include <iostream>
#include <sstream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::ostringstream streams[numRows];

        if (numRows == 1) {
            return s;
        }

        // w: s length, h: numRows
        ssize_t y {0};
        bool falling {true};
        for (size_t i{0}; i < s.size(); i++) {
            streams[y] << s.at(i);

            if (falling) {
                y++;
            } else {
                y--;
            }

            if (y == ssize_t(numRows)) {
                y -= 2;
                falling = false;
            }

            if (y < 0) {
                y = 0;
            }

            if (y == 0) {
                falling = true;
            }
        }

        for (size_t i = 1; i < size_t(numRows); i++) {
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
