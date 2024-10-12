#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int n)
{
    int reversed = 0;
    int original = n;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return original == reversed;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (isPalindrome(n)) 
    {
        printf("1");
    }
    else 
    {
        printf("0");
    }
    return 0;
}
