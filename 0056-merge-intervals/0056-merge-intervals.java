class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));
        int n = intervals.length;
        List<List<Integer>> result = new ArrayList<> ();

        int i = 0;
        while(i<n){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i+1<n && intervals[i+1][0]<=end ){
                end = Math.max(end,intervals[i+1][1]);
                i++;
            }
            result.add(List.of(start,end));
            i++;
        }
        int [][] results = new int [result.size()][2];
        
        for(i = 0; i<result.size();i++){
            for(int j = 0; j<2 ; j++){
                results[i][j]=result.get(i).get(j);
            }
        }
        return results;
    }
}