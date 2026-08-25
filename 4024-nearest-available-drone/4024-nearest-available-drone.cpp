class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int resind =-1;
        int mindiff = INT_MAX;
        int xi = target[0];
        int yi = target[1];
        for(int i = 0;i<drones.size();i++){
            int x = drones[i][0];
            int y= drones[i][1];
            int r = drones[i][2];
            int man = abs(xi-x)+abs(yi-y);
            if(man<=r && man<mindiff){
                resind = i;
                mindiff=man;
            }
        }
        return resind;
        
    }
};