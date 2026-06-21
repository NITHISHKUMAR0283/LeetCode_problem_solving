class Solution {
public:
    int maxDistance(string moves) {
        int down = 0;
        int right = 0;
        int under = 0;
        for(auto ele:moves){
            if(ele=='D'){
                down++;
            }
            else if(ele=='U')down--;
            else if(ele=='L')right--;
            else if(ele =='R'){
                right++;
            }
            else if(ele == '_'){
                under++;
            }
        }
        return abs(down)+abs(right)+under;
    }
};