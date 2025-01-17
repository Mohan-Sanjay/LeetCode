class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int l=s.size();
        vector<int> d(l,INT_MAX);
        for(int i=0;i<l;i++)
        {
            if(s[i]==c)
            {
               d[i]=0;
               for(int a=i+1;a<l;a++)
               {
                if(a-i>d[a]) continue;
                d[a]=a-i;
               }
               for(int p=0,v=i ;p<i;p++,v--)
               {
                if(v > d[p]) continue;
                d[p]=v;
               }
            }
        }
        return d;
    }
};