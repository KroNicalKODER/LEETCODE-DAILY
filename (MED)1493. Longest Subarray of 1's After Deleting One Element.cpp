class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0,s=0,e=0,n=nums.size();
        int ans = 0;
        while(s<n &&  e<n){
            while(e < n && nums[e] != 0) {
                e++;
                left++;
            }
            e++;
            while(e < n && nums[e] != 0) {
                e++;
                right++;
            }
            if(left == n) return n-1; 
            ans = max(ans,left+right);
            left = right;
            right = 0;
        }
        return ans;
    }
};
