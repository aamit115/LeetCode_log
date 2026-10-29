//xor two rules 1.cancel out same number and 2. xor with zero get the same number with which we applied xor
int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for(int i = 0; i< numsSize; i++){
        res =nums[i]^res;
    }
    return res;
}