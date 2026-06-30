class Solution {
    public List<String> generateValidStrings(int n, int k) {
        List<String> ans = new ArrayList<>();
        StringBuilder current = new StringBuilder("");
        explore(0,false,k,0,n,current,ans);
        return ans;
    }
    public void explore(int i , boolean prev ,int k , int cost , int n ,StringBuilder current ,List<String> ans ){
        // not taken
        if(cost>k)return; 
        if(i==n){
            ans.add(current.toString());
            return;
        }
        current.append("0");
        explore(i+1,false,k,cost,n,current,ans);
        if(current.length()>0){
            current.deleteCharAt(current.length()-1);
        }
        
        if(prev==false){
            current.append("1");
            explore(i+1,true,k,cost+i,n,current,ans);
            if(current.length()>0){
                current.deleteCharAt(current.length()-1);
            }
        }
    }
}