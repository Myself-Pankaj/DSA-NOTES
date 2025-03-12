#ifndef GCD_H
#define GCD_H

#include <bits/stdc++.h>
using namespace std;

// Function declaration
int gcd(int num1,int num2);
int euclidean_algo(int num1,int num2);


// Function implementation
int gcd(int num1,int num2) {
    
    int mini =min(num1,num2);
    int our_gcd = 0;

    //1st we will print all divissor of min(num1,num2)

    for(int i = mini; i>=1;i--){
        if(num1%i ==0 && num2%i ==0){
            our_gcd = i;
            break; //to get the largest gcd
        }
    }
    return our_gcd;
}

int euclidean_algo(int n1,int n2) {//5 10
 
  
    while(n2 !=0){
        int rem = n1%n2;
        n1 = n2;
        n2 =rem;
    }

    return n1;
}
#endif