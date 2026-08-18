class Solution {
public:
    
    
    struct Node{
        int first , last ;
        long long  gap;

        Node(int f=-1 ,int  l=-1 ,int  g=0){
            first = f;
            last = l;
            gap = g;
        }
        void modify(int f=-1,int l = -1 , int g = 0){
            this->first = f;
            this->last = l;
            this->gap = g;
        }
    };
    vector<Node>tree;
    void init(vector<int> & isPeak){
            int size =1 ;
            while(size<=isPeak.size()){
                size<<=1;
            }
            tree.resize(size<<1,Node());
            build(1,0,isPeak.size(),isPeak,tree);
        }
    long long calGap(int x){
        if(x<=0)return 0;
        return ((x-1)*(x-2)/2);
    }
    Node merge(const Node& L ,const  Node& R){
        if(L.first<0)return R;
        if(R.first<0)return L;
        return Node(L.first,R.last,L.gap+R.gap+calGap(R.first-L.last+1));
    }
    void build(int node , int left ,int right ,vector<int> & isPeak ,vector<Node>& tree){
        if(right-left==1){
            if(isPeak[left]==1){
                tree[node].modify(left,left,0);
            }
            else{
                tree[node].modify();
            }
            return;
        }
        int mid = (left+right)>>1;
        build(2*node , left,mid,isPeak,tree);
        build(2*node+1,mid,right,isPeak,tree);

        tree[node] = merge(tree[2*node],tree[2*node+1]);
    }
    Node query(int node, int left ,int right ,int leftq , int rightq, vector<Node> & tree){
        if(leftq<=left && right<=rightq)return tree[node];
        if(right<=leftq || left>=rightq){
            return Node();
        }
        int mid = (left+right)/2;
        return merge(query(node*2,left,mid,leftq,rightq,tree),query(node*2+1,mid,right,leftq,rightq,tree));
    }
    Node update(int node , int left , int right , int ind , bool isPeak){
        if(right-left==1){
            if(isPeak){
            tree[node].modify(left,left , 0);
            }
            else{
                tree[node].modify();
            }
            return tree[node];
        }
        int mid = (left+right)/2;
        if(ind>=mid){
            update(node*2+1,mid,right,ind,isPeak);
        }
        else{
            update(node*2,left,mid,ind,isPeak);
        }
        return tree[node]=merge(tree[2*node],tree[2*node+1]);
        
    }
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> peak(n,0);
        for(int i =1;i<n-1;i++){
            peak[i]=(nums[i-1]<nums[i]&& nums[i]>nums[i+1])?1:0;
        }
        init(peak);
        vector<long long> res;
        for(auto q:queries){
            if(q[0]==1){
                int l = q[1];
                int r = q[2];

                int len = q[2]-q[1]+1;
                if(len<3){
                    res.push_back(0);
                    continue;
                }
                    Node ans = query(1,0,n,l+1,r,tree);
                    if(ans.first==-1){
                        res.push_back(0);
                        continue;}
                    long long total = 1LL * (len-1)*(len-2)/2;
                    long long leftPart = calGap(ans.first-l+1);
                    long long middlePart = ans.gap;
                    long long rightPart = calGap(r-ans.last+1);
                    long long noPeak = leftPart + middlePart + rightPart;
                    long long answer = total - noPeak;
                    res.push_back(answer);}
                
            
            else {
    int index = q[1];
    int value = q[2];

    nums[index] = value;

    auto checkPeak = [&](int i) {

        if(i <= 0 || i >= n - 1)
            return;

        bool isPeak =
            (nums[i] > nums[i - 1] &&
             nums[i] > nums[i + 1]);

        update(1, 0, n, i, isPeak);
    };
    checkPeak(index - 1);
    checkPeak(index);
    checkPeak(index + 1);
}

        }return res;}
};