class Solution {
    public long[] minTimeMaxPower(int n, int[][] edges, int power, int[] cost, int source, int target) {
        long [][] adj = new long [n][n];
        int u,v,t;
        for (long [] row:adj){
            Arrays.fill(row,Long.MAX_VALUE);
        }
        for(int [] edge : edges){
            u = edge[0];
            v=edge[1];
            t=edge[2];
            adj[u][v]=Math.min(adj[u][v],t);
        }
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->{
            if(a[0]!=b[0]){
                return Long.compare(a[0],b[0]);
            }
            return Long.compare(b[1],a[1]);
        });
        pq.add(new long[]{0,power,source});
        
        long [][] min_time = new long[n][power+1];
        for(long [] row :min_time)Arrays.fill(row,Long.MAX_VALUE);
        int rempower , node;
        long  time ;
        while(!pq.isEmpty()){
            long [] top = pq.peek();
            time = top[0];
            rempower =(int) top[1];
            node =(int) top[2];
            pq.poll();
            if(node == target){
                return new long []{time,rempower};
            }
            if(time>min_time[node][rempower])continue;
            if(rempower <cost[node])continue;
            int nextPow = rempower-cost[node];
            for(int nei =0;nei<adj[node].length;nei++){
                if(adj[node][nei]==Long.MAX_VALUE)continue;

                long nextTime = time+adj[node][nei];

                if(nextTime<min_time[nei][nextPow]){
                    min_time[nei][nextPow]=nextTime;
                    pq.add(new long []{nextTime,nextPow,nei});
                }           

            }
            
        }
        return new long []{-1,-1};
    }
}