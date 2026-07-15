class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*(n+1);
        int even = n*n;
        return gcd(odd,even);
    }
};