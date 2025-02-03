class Solution {
public:
    void bfs(int i,vector<vector<int>>&con,vector<bool>&visit,queue<int>&q)
    {
        q.push(i);
        while(q.size())
        {
            int n=q.front();
            q.pop();
            visit[n]=true;
            for(int j=0;j<con[n].size();j++)
            {
                    if(con[n][j] && visit[j]==false)
                    {
                        q.push(j);
                        visit[j]=true;
                    }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visit(n,false);
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                bfs(i,isConnected,visit,q);
                count++;
            }
        }
        return count;
    }
};