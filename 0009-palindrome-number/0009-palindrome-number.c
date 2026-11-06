bool isPalindrome(int x) {
int num=x;
    long long r=0; 
    if(x<0)
     return 0;
    while(num!=0){
    r= r*10+(num%10);
    num=num/10;
    }
if(x==r)
 return 1;
else    
    return 0;
}