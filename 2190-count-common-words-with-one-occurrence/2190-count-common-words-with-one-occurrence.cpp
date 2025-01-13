class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>m1;
        unordered_map<string,int>m2;
        for(string s:words1)
            m1[s]+=1;
        for(string s:words2)
            m2[s]+=1;
        int res=0;
        for(string s:words1)
            if(m1[s]==1 && m2[s]==1) res++;
        return res;
    }
};