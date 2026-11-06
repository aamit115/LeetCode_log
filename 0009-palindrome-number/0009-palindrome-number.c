bool isPalindrome(int x) {
    int n=x;
    long long r=0; 
    if(x<0)
     return 0;
    while(n!=0){
    r= r*10+(n%10);
    n=n/10;
    }
    if(x==r)
     return 1;
     else
     return 0;
}