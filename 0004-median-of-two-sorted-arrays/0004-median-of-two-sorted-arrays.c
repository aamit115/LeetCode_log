double findMedianSortedArrays(int nums1[], int m,
                              int nums2[], int n)
{
    // Always perform binary search on the smaller array
    if (m > n)
        return findMedianSortedArrays(nums2, n, nums1, m);

    int low = 0;
    int high = m;

    int total = m + n;
    int half = (total + 1) / 2;

    while (low <= high)
    {
        // Partition position in both arrays
        int cut1 = (low + high) / 2;
        int cut2 = half - cut1;

        // Left and right elements of first array
        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        // Left and right elements of second array
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        // Correct partition found
        if (left1 <= right2 && left2 <= right1)
        {
            // Odd number of elements
            if (total % 2 == 1)
                return (double)(left1 > left2 ? left1 : left2);

            // Even number of elements
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return ((double)maxLeft + minRight) / 2.0;
        }

        // Move towards left in first array
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }

        // Move towards right in first array
        else
        {
            low = cut1 + 1;
        }
    }

    return 0.0;
}