class Solution {
public:
    // i,j are present location of pointer in the board 
    // k is index of present position in the word
    bool check(vector<vector<char>>& board, string& word, int i, int j, int k) {
            if(k == word.length()) return true;

            if(
                (0 <= i && i < board.size()) && 
                (0 <= j && j < board[0].size()) &&
                board[i][j] == word[k]
                ) 
                {
                    char ch = board[i][j];
                    board[i][j] = '0';
                    k++;
                    if(
                        check(board, word, i+1, j, k) ||
                        check(board, word, i, j+1, k) ||
                        check(board, word, i-1, j, k) ||
                        check(board, word, i, j-1, k)
                        ) return true;
                    board[i][j] = ch;
            }
            return false;
        }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(check(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};