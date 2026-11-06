#include <stdbool.h>
bool isPalindrome(int x) {
long reversedNum = 0; 
int originalX = x;
while (x > 0) {
    int lastDigit = x % 10;
    reversedNum = reversedNum * 10 + lastDigit; 
    x = x / 10; 
}
return originalX == reversedNum;}
