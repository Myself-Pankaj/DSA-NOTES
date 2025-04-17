#include<bits/stdc++.h>
using namespace std;
class basicRecurssion{
    public:
    void print_name_n_time(int n){
        if(n == 0) return;
        cout<<"Pankaj\n";

        print_name_n_time(n-1);
        cout<<"Kholiya\n";
    }

    void print_one_to_n(int n){
        if(n ==0) return ;

        print_one_to_n(n-1);
        cout<<n<<" ";
    }
    void print_n_to_one(int n){
        if(n ==0) return ;

        cout<<n<<" ";
        print_one_to_n(n-1);
    }
    int sum_of_first_n_num(int n){
        
        if(n ==0) return 0;

        return sum_of_first_n_num(n-1)+n;
    }
    int factorial(int n){
        if(n ==1) return 1;

        return factorial(n-1)*n;
    }
    void revarr(vector<int>&arr,int i,int n){
        if(i>=n) return;
        swap(arr[i],arr[n]);
        revarr(arr,i+1,n-1);
    }

    int fibobacchi(int n){
        
        if(n == 1) return 1;
        if(n==2) return 2;

        return fibobacchi(n-1)+fibobacchi(n-2);
    }
    int  adddigit(int n ){
        if(n == 0 ) return 0;

        int sum = n%10;
        return adddigit(n/10)+sum;


    }
    // void revStack(stack<int>& st){
    //     if(st.empty()){
    //         return;
    //     }
    //     int top = st.top();
    //     st.pop();
        
    //     revStack(st);
    // }

    void arrsum(int index, vector<int>& arr,int &sum,int n){
        if(index == n){
            return;
        }
        //15
        sum+=arr[index];
        arrsum(index+1,arr,sum,n);
        
    }
    int countGoodNumbers(long long n) {
        if(n == 0) return 1;
        if(n == 1) return 5;
        if(n%2 ==0){
            return countGoodNumbers(n-2)*20;
        }else{
            return countGoodNumbers(n-1)*5;
        }
    }
};