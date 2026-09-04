class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int top = 0 , right = matrix[0].length-1 , bottom =  matrix.length-1, left = 0;
        List<Integer> solution = new ArrayList<>();
        while(top<=bottom && left<=right){
            
            for(int i = left ; i<=right ; i++){
                solution.add(matrix[top][i]);
            }
            top++;
            
            for(int j = top ; j<=bottom ; j++){
                solution.add(matrix[j][right]);
            }
            right--; 
            if(top<=bottom){
            for(int j = right ; j>=left; j--){
                solution.add(matrix[bottom][j]);
            }
            bottom--; }
            if(left<=right){
                
            for(int i = bottom ; i>=top ; i--){
                solution.add(matrix[i][left]);
            }
            left++;}
            

        }
        return solution;
    }
}