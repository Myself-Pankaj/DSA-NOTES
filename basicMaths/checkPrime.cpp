#ifndef checckprime_H
#define checckprime_H


#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n);

bool isPrime(int n) {
    if(n==1) return true;
    if(n ==2) return true;
    for(int i = 2;i<n;i++){
        if(n%i ==0) return false;
    }
    return true;
}

bool isPrime_optimal(int n){
    if(n <=1) return false;
    if(n ==2 || n==3) return true;
    if (n % 2 == 0) return false;    
    for(int i = 3 ;i*i<=n;i+=2){
        if(n%i ==0) return false;
    }
    return true;
}
bool isPrime_optimal1(int n){
    if(n <=1) return false;
    if(n ==2 || n==3) return true;
    if (n % 2 == 0) return false;    
    if(n%3 ==0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

#endif