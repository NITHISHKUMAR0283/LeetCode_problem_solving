class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n,0);

        queue <int> q;

        vector<vector<int>> contri(n);

        for(auto i = 0;i<n ;i++){
            outdegree[i]=graph[i].size();
            for(const auto & v : graph[i]){
                contri[v].push_back(i);
            }
        }

        for(int i = 0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safe;
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            safe.push_back(v);
            for(auto c : contri[v]){
                outdegree[c]--;
                if(outdegree[c]==0){
                    q.push(c);
                }
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};