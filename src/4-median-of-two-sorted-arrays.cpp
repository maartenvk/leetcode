#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        auto& main_array = nums1;
        std::sort(main_array.begin(), main_array.end());

        double median = main_array[main_array.size() / 2];

        bool even = nums1.size() % 2 == 0;
        if (even) {
            median = (median + main_array[main_array.size() / 2 - 1]) / 2.0;
        }

        return median;
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
