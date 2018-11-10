class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_row = list(map(max, grid))
        
        trans_grid = list(map(list, zip(*grid)))
        max_col = list(map(max, trans_grid))
        
        increase = 0
        for i, mr in enumerate(max_row):
            for j, mc in enumerate(max_col):
                increase += (min(mr, mc) - grid[i][j])
        
        return increase