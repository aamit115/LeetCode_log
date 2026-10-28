int* sortedSquares(int* nums, int numsSize, int* returnSize) {
int* ar = (int*)malloc(numsSize * sizeof(int));
*returnSize = numsSize;
int left = 0, right = numsSize - 1;
int position = numsSize - 1;
while (left <= right) {
int leftsquare = nums[left] * nums[left];
int rightsquare = nums[right] * nums[right];
if (leftsquare > rightsquare) {
ar[position] = leftsquare;
left++;
}
else {
ar[position] = rightsquare;
right--;
}
position--;
}
return ar;
}