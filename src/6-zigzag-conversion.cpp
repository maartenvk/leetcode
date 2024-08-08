#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

template <typename T>
class matrix {
public:
    std::vector<T> data;
    size_t w, h;

    matrix(size_t w, size_t h) : data(w*h), w{w}, h{h} {}

    typename std::vector<T>::iterator operator[](size_t row) {
        if (row > h) {
            std::cerr << "Indexing at " << row << std::endl;
            throw std::out_of_range{"accessing"};
        }

        return data.begin() + (row * w);
    }
};

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        matrix<char> m(s.length(), size_t(numRows));
        size_t y{0}, x{0};
        bool going_up{false};
        for (size_t i{0}; i < s.size(); i++) {
            m[y][x] = s.at(i);

            if (going_up) {
                x++;
                if (--y == 0) {
                    going_up = false;
                }
            } else {
                if (++y == m.h) {
                    going_up = true;
                    y -= 2, x++;
                }
            }
        }

        std::ostringstream os{""};

        // flatten vector
        for (char c : m.data) {
            if (c == '\0') {
                continue;
            }

            os << c;
        }

        return os.str();
    }

    void print_matrix(matrix<char> m) {
        for (size_t y = 0; y < m.h; y++) {
            for (size_t x = 0; x < m.w; x++) {
                char c = m[y][x];
                if (c == '\0') {
                    c = '-';
                }

                std::cout << c;
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    Solution s;
    auto result = s.convert("PAYPALISHIRING", 3);
    std::cout << result << std::endl;
    return 0;
}
