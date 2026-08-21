class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int water = 0;

        for(int i = 1 ;i<height.size();i++){
            int curr = height[i];
            int obs = 0;
            int left = -1;
            while(!st.empty() && height[st.top()]<=curr){
                int mid = st.top();
                st.pop();
                if(st.empty())break;
                int left = st.top();
                int heights = min(height[left],height[i])-height[mid];
                int width = i-left-1;
                water+=width*heights;
        }
        st.push(i);}
        
    return water;
    }
};