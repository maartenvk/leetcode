#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> array;

        const size_t total_size = nums1.size() + nums2.size();
        const size_t middle = total_size / 2;
        const bool is_even = total_size % 2 == 0;

        std::vector<int>::const_iterator it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() || it2 != nums2.end()) {
            int a = std::numeric_limits<int>::max();
            int b = std::numeric_limits<int>::max();

            if (it1 != nums1.end()) {
                a = *it1;
            }

            if (it2 != nums2.end()) {
                b = *it2;
            }

            if (a < b) {
                array.push_back(a);
                it1++;
            } else {
                array.push_back(b);
                it2++;
            }

            if (array.size() == (middle + 1)) [[unlikely]] {
                double median = array[middle];
                if (is_even) {
                    median = (median + array[middle - 1]) / 2.0;
                }

                return median;
            }
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
