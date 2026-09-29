class Solution {
public:

    int ceiling(int a,int b){
        
        return (a+b-1)/b;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     int low=1;
     int maxn;
     for(int x:nums){
           maxn=max(maxn,x);
       }
        int high=maxn;
     while(low<=high){
        int mid=(low+high)/2;
        int result=0;
        for(int ele:nums){
            result+=ceiling(ele,mid);
        }
        if(result<=threshold){
            high=mid-1;
            
        }
        else low=mid+1;;
        }
     return low;
    }
};