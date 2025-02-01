class Solution {
public:
    bool valid(vector<vector<char>>& board,int i,int j,char num)
    {
        for(int k=0;k<9;k++)
            if(board[k][j]==num)
                return false;
        for(int k=0;k<9;k++)
            if(board[i][k]==num)
                return false;
        for(int m=0;m<3;m++)
            for(int n=0;n<3;n++)
                if(board[3*(i/3) + m][3*(j/3) +n]==num)
                    return false;
        return true;
    }
    bool find(vector<vector<char>>& board,int i ,int j)
    {
        if(i>=9) return true;
        if(j>=9)
        {
            i=i+1;
            j=0;
        }
        if(i>=9) return true;
        if(board[i][j]!='.')
            return  find(board,i,j+1);
        for(char num='1';num<='9';num++)
        {
            if(valid(board,i,j,num))
            {
                board[i][j]=num;
                if(find(board,i,j+1))
                {
                    return true;
                }
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(board,0,0);
    }
};