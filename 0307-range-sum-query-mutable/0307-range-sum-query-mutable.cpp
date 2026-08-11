class Segment{
    private:
    vector<int> tree;
    public:
    void init(vector<int>& nums){
        int n = nums.size();
        tree.resize(n*4,0);
        build(nums,1,0,n-1);

    }

    void build(vector<int> & nums,int node , int start , int end ){
        if(start ==end){
            tree[node]=nums[start];
            return;
        }
        int mid = (start+end)/2;
        build(nums,2*node,start,mid);
        build(nums,2*node+1,mid+1,end);

        tree[node]=tree[2*node]+tree[2*node+1];
        
}
    int  query(int start , int end , int left , int right , int node){
        if(right<start|| left>end)return 0;
        if(left<= start && end<=right)return tree[node];

        int mid = (start+end)/2;
        int l = query(start,mid,left,right,node*2);
        int r = query(mid+1,end,left,right,node*2+1);

        return l+r;
    }
    void update(int node , int start , int end , int val,int ind){
        if(start==end){
            tree[node]=val;
            return;}
        int mid = (start+end)/2;
        if(ind<=mid){
            update(node*2,start,mid,val,ind);
        }
        else{
            update(node*2+1,mid+1,end,val,ind);
        }
        tree[node]=tree[node*2]+tree[node*2+1];
    }


};
class NumArray {
public:
    Segment s;
    int n =0;
    NumArray(vector<int>& nums) {
        s.init(nums);
        n = nums.size();
    }
    
    void update(int index, int val) {
        s.update(1,0,n-1,val,index);
    }
    
    int sumRange(int left, int right) {
        int sum = s.query(0,n-1,left,right,1);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */