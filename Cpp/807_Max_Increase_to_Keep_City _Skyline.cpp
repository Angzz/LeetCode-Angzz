class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int increase = 0;
        int row = grid.size(), col = grid[0].size();
        int i, j;
   
        // Compute max along row
        vector<int> max_row;
        for (i = 0; i < row; i++)
        {
            int tmp = grid[i][0];
            for (j = 0; j < col; j++)
                if (tmp < grid[i][j]) tmp = grid[i][j];
            max_row.push_back(tmp);
        }
        
        // Compute max along col
        vector<int> max_col;
        for (j = 0; j < col; j++)
        {
            int tmp = grid[0][j];
            for(i = 0; i < row; i++)
                if (tmp < grid[i][j]) tmp = grid[i][j];
            max_col.push_back(tmp);
        }
        
        // Compute difference
        int min, diff;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                min = max_row[i]<max_col[j]?max_row[i]:max_col[j];
                diff = min - grid[i][j];  
                increase += diff;
            }
        }
        
        return increase;
    }
};