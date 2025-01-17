class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2;
        int l=s.size();
        for(int i=0;i<l;i++)
        {
            if((m1.count(s[i])==1 and m1[s[i]]!=t[i]) or (m2.count(t[i])==1 and m2[t[i]]!=s[i])) return false;
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        return true;
    }
};