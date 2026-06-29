class Solution {
    public String[] createGrid(int m, int n) {
        String [] grid = new String [m];
        String start = ".".repeat(n);
        String r = "#";
        String inter = r.repeat(n-1);
        String d = ".";
        inter=inter+d;
        grid[0]=start;
        for(int i = 1;i<m;i++){
            grid[i]=inter;
        }
        return grid;
    }
}