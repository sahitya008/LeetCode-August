class Solution {
public:
   
     int solve(vector<int>& candidates, int target,vector<int> &dp){
         //BC1
         if(target==0)
             return 1;
         if(target<0)
             return 0;
        int ans=0;
         if(dp[target]!=-1)
             return dp[target];
         for(int i=0;i<candidates.size();i++){
            ans+=solve(candidates,target-candidates[i],dp);
        }    
         dp[target]=ans;
         return dp[target];
     }
     int combinationSum4(vector<int>& candidates, int target) {
         vector<int> dp(target+1,-1);
         return solve(candidates, target,dp);   
     }
};