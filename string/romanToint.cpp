#include <bits/stdc++.h>
using namespace std;

class RomanToInt{
    private:
    int value(char c){
        if(c == 'I') return 1;
        else if(c =='V') return 5;
        else if(c == 'X') return 10;
        else if(c =='L') return 50;
        else if(c =='C') return 100;
        else if(c =='D') return 500;
        else if(c =='M') return 1000;
        return -1;
    }
    public:
    int romanToInt(string s) {
        int len = s.length();
        int num = 0;
        for(int i = 0 ;i<len;i++){
            int s1 = value(s[i]);
            if(i+1<len){
                int s2 = value(s[i+1]);
                if(s1<=s2){
                    num = num+s1;
                }else{
                    num= num+(s2-s1);
                    i++;
                }
            }else{
                num+=s1;
            }
        }
        return num;
    }
};