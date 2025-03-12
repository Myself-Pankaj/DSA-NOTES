#ifndef AMSTRONG_H
#define AMSTRONG_H


#include<bits/stdc++.h>
using namespace std;
bool isArmstrong(int n);

bool isArmstrong(int n) {
    int og_num = n;
    int count = 0;

    while(og_num){
        count++;
        og_num/=10;
    }
    og_num = n; int sum = 0;
    while(og_num){
        int ld = og_num%10;
        sum+=pow(ld,count);
        og_num/=10;
    }
    return sum == n;
}

#endif