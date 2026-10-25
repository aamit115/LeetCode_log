int* twoSum(int*nums,int numsize,int target,int*returnsize){

for(int i=0;i<numsize;i++){

for(int j= i+1;j<numsize;j++){

if(nums[i] +nums[j]==target){

int* result = malloc(2 *sizeof(int));

result[0]=i;

result[1]=j;

*returnsize = 2;

return result;}}}

*returnsize =0;

return NULL;}