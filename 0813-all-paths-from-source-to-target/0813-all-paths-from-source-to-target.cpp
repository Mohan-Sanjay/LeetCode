class Solution {
public:
    void findpaths(int i,vector<vector<int>>& graph,vector<bool> & visit,vector<int>& r1,vector<vector<int>>& res)
    {
        if(i==graph.size()-1)
        {
            r1.push_back(i);
            res.push_back(r1);
            r1.pop_back();
            return;
        }
        visit[i]=true;
        r1.push_back(i);
        for(int a:graph[i])
        {
            if(visit[a]==false)
            {
                findpaths(a,graph,visit,r1,res);
            }
        }
        r1.pop_back();
        visit[i]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int>r1;
        vector<bool>visit(graph.size(),false);
        findpaths(0,graph,visit,r1,res);
        return res;
    }
};