double findMaxAverage(int* nums, int numsSize, int k) {
    double Sum = 0;
    for (int i = 0; i < k; i++) {
        Sum += nums[i];}
    double maxSum = Sum;
    for (int i = k; i < numsSize; i++) {
        Sum = Sum - nums[i - k] + nums[i];
        
        if (Sum > maxSum) {
            maxSum = Sum;
        }
    }
     return maxSum / k;}
// learned the logic from Nikhil Lohia and modified with help of the best optimized solution.