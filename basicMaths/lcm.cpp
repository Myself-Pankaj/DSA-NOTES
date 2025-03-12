#ifndef LCM_H
#define LCM_H



int my_lcm(int n1,int n2);

int temp_gcd(int n1,int n2){

    if(n1<n2){
        int temp = n2;//252
        n2 = n1;//105
        n1 = temp;//252
    }

    while(n1%n2 !=0){
        int rem = n1%n2;
        n1=n2;
        n2=rem;
    }
    return n2;
}
int my_lcm(int n1,int n2){
    int our_lcm = 1;

    int numerator = n1*n2;
    int deno = temp_gcd(n1,n2);

    our_lcm = numerator/deno;
    return our_lcm;
}



#endif