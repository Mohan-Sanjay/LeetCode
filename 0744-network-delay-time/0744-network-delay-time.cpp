class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        n++;
        vector<int> res(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int> & t:times)
        {
            int u=t[0];
            int v=t[1];
            int w=t[2];
            adj[u].push_back({w,v});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> queue;
        queue.push({0,k});
        res[k]=0;
        while(queue.size())
        {
            pair<int,int> p=queue.top();
            queue.pop();
            int d=p.first;
            int v=p.second;
            for(pair<int,int> & a:adj[v])
            {
                int cd=a.first;
                int cv=a.second;
                if(d+cd<res[cv])
                {
                    res[cv]=d+cd;
                    queue.push({res[cv],cv});
                }
            }
        }
        int max=0;
        for(int i=1;i<n;i++)
        {
            if(res[i]==INT_MAX) return -1;
            max=fmax(max,res[i]);
        }
        return max;
    }
};