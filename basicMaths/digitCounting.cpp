#ifndef COUNTDIGIT_H
#define COUNTDIGIT_H

// Function declaration
int count_digit(int n);

// Function implementation
int count_digit(int n) {
    int count = 0;

    while (n)
    {
        count++;
        n=n/10;
    }
    return count;
}

#endif