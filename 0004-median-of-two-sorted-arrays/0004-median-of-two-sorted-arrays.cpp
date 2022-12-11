class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // make sure nums1 is the shorter array
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        // binary search for median
        int low = 0;
        int high = m;
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // get the maximum elements in the left partitions of each array
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];

            // get the minimum elements in the right partitions of each array
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // found the median
                if ((m + n) % 2 == 0) {
                    // even number of elements, average of middle elements
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // odd number of elements, middle element is the median
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // median is in the left half of array 1
                high = partition1 - 1;
            } else {
                // median is in the right half of array 1
                low = partition1 + 1;
            }
        }

        // should never reach here
        return -1;
    }
};