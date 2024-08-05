#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        const size_t total_size = nums1.size() + nums2.size();
        const size_t middle = total_size / 2;
        const bool is_even = ~total_size & 1;

        size_t i {0};

        int data[2];
        std::vector<int>::const_iterator it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() || it2 != nums2.end()) {
            int a, b;
            a = b = std::numeric_limits<int>::max();

            if (it1 != nums1.end()) {
                a = *it1;
            }

            if (it2 != nums2.end()) {
                b = *it2;
            }

            if (a < b) {
                data[i & 1] = a;
                it1++;
            } else {
                data[i & 1] = b;
                it2++;
            }

            if (i == middle) [[unlikely]] {
                double median = data[i & 1];
                if (is_even) {
                    median = (median + data[(i - 1) & 1]) / 2.0;
                }

                return median;
            }

            i++;
        }

        return 0;
    }
};

int main() {
    Solution s;

    std::vector a {1, 2};
    std::vector b {3, 4};

    auto result = s.findMedianSortedArrays(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
