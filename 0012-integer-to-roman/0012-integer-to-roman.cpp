class Solution {
public:
    int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* s[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}; 
    string DtoR(int num,int i)
    {
    if(num<=0) return "";
    string st="";
    if(num>=n[i])
    {
        st=s[i];
        num-=n[i];
    }
    else i++;
    return st+DtoR(num,i);
    }
    string intToRoman(int num) {
    return DtoR(num,0);
    }
};