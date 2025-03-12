#ifndef ISNUMPALINDROME_H
#define ISNUMPALINDROME_H

// Function declaration
bool is_palindrome(int n);

// Function implementation
bool is_palindrome(int n) {
    int original_num = n;
    int reverse_num = 0;

    while (n)
    {
        int last_digit = n%10;
        reverse_num = reverse_num*10+last_digit;
        n=n/10;
    }
    return reverse_num == original_num;
}

#endif