class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int k=0;
        while(k<m)
        {
            int i=0,j=k;
            int num=matrix[i][j];
            while(i<n and j<m)
            {
                if(matrix[i][j]!=num)
                    return false;
                i++;
                j++;
            }
            k++;
        }
        
        // row wise
        k=n-1;
        while(k>=0)
        {
            int i=k,j=0;
            int num=matrix[i][j];
            while(i<n and j<m)
            {
                if(matrix[i][j]!=num)
                    return false;
                i++;
                j++;
            }
            k--;
        }
        return true;
    }
};

/*
[[36,59,71,15,26,82,87],[56,36,59,71,15,26,82],[15,0,36,59,71,15,26]]

36 59 71 15 26 82 87
56 36 59 71 15 26 82
15 00 36 59 71 15 26

*/