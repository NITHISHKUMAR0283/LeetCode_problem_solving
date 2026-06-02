class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int up = 0;
        int down = 0;
        int current = 0;
        int n = arr.size();
        int maxi = 0;
        
        if(n<3)return 0;
        while(current<n){
            bool ups = false;
            int left = current;
            while(current<n-1 && arr[current]<arr[current+1]){
                current++;
                ups=true;
            }
            if(!ups){
                current++;
                continue;
            }
            ups = false;
            
            while(current<n-1 && arr[current]>arr[current+1]){
                current++;
                ups=true;}
            
            if(!ups){
                current++;
                continue;
            }
            maxi = max(maxi , current-left+1);
        }
        return maxi;
    }
};