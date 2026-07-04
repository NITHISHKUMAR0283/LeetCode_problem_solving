class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int top_left=0 , top_right=m-1 , bottom_right = n-1 , bottom_left = 0;

        List<Integer> ans = new ArrayList<>();

        while(top_left<=bottom_right  && top_right>=bottom_left){    
            for(int j = bottom_left ; j<=top_right ; j++){
                ans.add(matrix[top_left][j]);
            }
            top_left++;
            if(top_left>bottom_right)break;
            for(int i = top_left ; i<=bottom_right ; i++){
                ans.add(matrix[i][top_right]);
            }
            top_right--;
            if(top_right<bottom_left)break;
            for(int j = top_right ; j>=bottom_left ; j--){
                ans.add(matrix[bottom_right][j]);
            }
            bottom_right--;
            if(bottom_right<top_left)break;
            for(int i = bottom_right ; i>=top_left ; i--){
                ans.add(matrix[i][bottom_left]);
            }
            bottom_left++;
        }
        return ans;

    }
}