class Solution {
public:
    bool find(vector<bool>& path,vector<bool>& visit,vector<vector<int>>& adj, int i)
    {
        visit[i]=true;
        path[i]=true;
        for(int a:adj[i])
        {
           if(path[a])
                return false;
            if(!visit[a])
            {
                if(find(path,visit,adj,a)==false)
                    return false;
            }
        }
        path[i]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int>& e:prerequisites)
            adj[e[0]].push_back(e[1]);
        vector<bool> visit(adj.size(),false);
        vector<bool> path (adj.size(),false);
        bool b=true;
        for(int i=0;i<adj.size();i++)
        {
            if(!visit[i])
            {
                if(find(path,visit,adj,i)==false)
                    b=false;
            }
        }
        return b;
    }
};