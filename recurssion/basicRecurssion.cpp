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
};