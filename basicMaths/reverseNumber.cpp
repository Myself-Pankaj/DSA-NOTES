#ifndef REVDIGIT_H
#define REVDIGIT_H

// Function declaration
int reverse_number(int n);

// Function implementation
int reverse_number(int n) {
    int digit = 0;

    while (n)
    {
        int last_digit = n %10;
        digit = digit*10+last_digit;
        n=n/10;
    }
    return digit;
}

#endif