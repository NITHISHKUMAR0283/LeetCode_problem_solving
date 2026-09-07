class Solution {
    public int totalFruit(int[] fruits) {
        int lastFruit = -1 , secondlastFruit = -1;
        int lastCount = 0 , currCount = 0;
        int n = fruits.length;
        int ans = 0;
        for(int i =  0 ; i<n ; i++ ){
            if(fruits[i] == lastFruit || fruits[i]==secondlastFruit){
                currCount++;
            }
            else{
                currCount=1+lastCount;
            }
            if(fruits[i]==lastFruit)lastCount++;
            else{
                secondlastFruit = lastFruit;
                lastFruit = fruits[i];
                lastCount = 1;
            }
            ans = Math.max(ans, currCount);

        }
        return ans;
    }
}