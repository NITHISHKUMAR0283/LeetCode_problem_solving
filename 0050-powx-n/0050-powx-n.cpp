class Solution {
public:
    double Pow(double base , double x , long long  n ){
        if(n==0)return 1.0;
        if(n==1)return x;
        if(n%2==0)return Pow(base,x*x,n/2);
        return x*Pow(base,x,n-1);
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n<0)return (double)1/Pow(x,x,-N);
        return Pow(x,x,n);
    }
};