class Solution {
public:
    void maxRectange(vector<int> & histogram,int & sol){
        stack<int> stack;
        histogram.push_back(0);

        for(int i = 0;i<histogram.size();i++){
            while(!stack.empty() && histogram[stack.top()]>histogram[i]){
                int height = histogram[stack.top()];
                stack.pop();
                int width = stack.empty()?i:i-stack.top()-1;
                sol = max(sol,height*width);
            }
            stack.push(i);
        }
        histogram.pop_back();
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sol = 0;
        vector<int> histogram (m,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j]=0;
                }

            }
            maxRectange(histogram,sol);
        }
        return sol;
    }
};