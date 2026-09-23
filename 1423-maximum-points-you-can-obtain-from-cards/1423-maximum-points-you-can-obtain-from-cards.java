class Solution {
    public int maxScore(int[] cardPoints, int k) {
    
        int n = cardPoints.length;
        int sF = 0;
        int sB = 0;
        int solution = 0; 
        for(int i = 0 ; i<k; i++){
            sF+=cardPoints[i];
        }
        solution = sF;
        for(int i = k-1 ; i>=0 ; i--){
            int back = i+(n-k);
            sF  -=cardPoints[i];
            sB+=cardPoints[back];
            solution = Math.max(solution , sF+sB);
        }
        return solution;
    }
}