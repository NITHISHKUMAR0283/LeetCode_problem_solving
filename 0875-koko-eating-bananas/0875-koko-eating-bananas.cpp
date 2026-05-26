class Solution {
public:
    bool finishable(int speed, vector<int>& piles,int h){
        int time = 0;
        for(auto pile : piles){
            int c_time = pile/speed;
            if(c_time*speed!=pile){                
                c_time++;                
                }
            time+=c_time;
        }
        if(time>h)return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element (piles.begin(),piles.end());
        while(low<high){
            int mid = (low+high)/2;
            if(finishable(mid,piles,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
};