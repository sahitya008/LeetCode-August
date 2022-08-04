class Solution {
public:
   /*METHOD 1: recursive code giving TLE 
   int uniquePaths(int m, int n) {
        int i=0,j=0;
        int ans= countPath(m,n,i,j);
        return ans;
    }
    int countPath(int m, int n, int i,int j){
      //if(i<0 || j<0) return 0; this is useless  as we are not goinng left
       if(i==m-1 && j== n-1) return 1;
        if(i>=m || j>=n) return 0;
        else {
               return countPath(m,n,i+1,j) + countPath(m,n,i,j+1);
     }
    }*/
    //METHOD 2: DP with memroization
   int uniquePaths(int m, int n) {
         int i=0,j=0;
       vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans= countPath(m,n,i,j,dp);
        return ans;
   } 
     int countPath(int m, int n, int i,int j, vector<vector<int>> &dp){
      if(i==m-1 && j== n-1) return 1;
        if(i>=m || j>=n) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
         else {
               return dp[i][j]= countPath(m,n,i+1,j,dp) + countPath(m,n,i,j+1,dp);
     }   
     }
};