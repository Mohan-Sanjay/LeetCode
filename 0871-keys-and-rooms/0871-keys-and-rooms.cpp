class Solution {
public:
    int find(int i,vector<bool>& visit,vector<vector<int>>& rooms)
    {
        if(visit[i])    return 0;
        int s=0;
        visit[i]=true;
        for(int k:rooms[i])
            s=s+find(k,visit,rooms);
        return 1+s;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visit(rooms.size(),false);
        return rooms.size()==find(0,visit,rooms);
    }
};