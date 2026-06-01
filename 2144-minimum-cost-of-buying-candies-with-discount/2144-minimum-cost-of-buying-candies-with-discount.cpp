class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int r = cost.size()-1;
        int costs = 0;
        while(r>-1){
            int count = 0;
            while(r>-1 && count<2){
                
                costs+=cost[r--];
                count++;
            }
            r-=1;
        }
        return costs;
    }
};