class Solution {
    private long MOD = 1_000_000_007;
    public int countGoodNumbers(long n) {
        // even indices - 5
        // prime odd = 4
        long odd = n/2;
        long even = (n+1)/2;
        
        long even_choice = power(5,even);
        long odd_choice = power(4,odd);

        return (int)((even_choice*odd_choice)%MOD);
        
        
    }
    private long power (long base , long exp){
        long res = 1;
        base = base%MOD;
        while(exp>0){
            if(exp%2==1){
                res = (res*base)%MOD;
            }
            base = (base*base)%MOD;
            exp/=2;
        }
        return res;
    }
}