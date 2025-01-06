/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

        int ** res=(int **)malloc(sizeof(int *)*n);
        for(int i=0;i<n;i++)
        {
            res[i]=(int *)malloc(sizeof(int)*n);
        }
        int loop=0;
        int i=0,j=0;
        int up=-1,right=n,down=n,left=-1;
        int ** r;
        while(loop<n*n)
        {
            j=left+1;
            while(loop<n*n && right>-1 && j<right)
            {
                res[up+1][j]=loop+1;
                loop++;
                j++;
            }
            up++;
            i=up+1;
            while(loop<n*n && down>-1 && i<down)
            {
                res[i][right-1]=loop+1;
                loop++;
                i++;
            }
            right--;
            j=right-1;
            while(loop<n*n && left<n && j>left)
            {
                res[down-1][j]=loop+1;
                loop++;
                j--;
            }
            down--;
            i=down-1;
            while(loop<n*n && up<n && i>up)
            {
                res[i][left+1]=loop+1;
                loop++;
                i--;
            }
            left++;
        }
        *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }
        return res;
}