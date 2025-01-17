class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,st=0,p=0;
        for(char c:s)
        {
            for(i=st;i<t.size();i++)
            {
                if(c==t[i])
                {
                    p++;
                    st=i+1;
                    break;
                }
            }
        }
        return p==s.size();
    }
};