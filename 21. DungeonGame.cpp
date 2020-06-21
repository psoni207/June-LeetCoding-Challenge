class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int> > dp(m,vector<int>(n));
        dp[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1 - dungeon[m-1][n-1];
        
        for(int i = m-2; i >= 0; i -= 1){
            dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 1);
        }
        for(int j = n-2; j >= 0; j -= 1){
            dp[m-1][j] = max(dp[m-1][j+1] - dungeon[m-1][j], 1);
        }        
        
        for(int i = m-2; i >= 0; i -= 1){
            for(int j = n-2; j >= 0; j -= 1){
                dp[i][j] = max( min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            }
        }
        
        return dp[0][0];
    }
};