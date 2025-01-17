class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m1;
        for(char c:s)
            m1[c]=m1[c]+1;
        for(int i=0;i<s.size();i++)
        {
            if(m1[s[i]]==1) return i;
        }
        return -1;
    }
};