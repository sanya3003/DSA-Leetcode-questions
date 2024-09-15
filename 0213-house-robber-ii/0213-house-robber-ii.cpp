class Solution {
public:
    int maximumSubsequenceSum(vector<int> &nums1){
        int n = nums1.size();
        int prev = nums1[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums1[i];
            if(i>1) take+=prev2;
            int nontake = 0+prev;
            int curi = max(take,nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }
        return max(maximumSubsequenceSum(temp1), maximumSubsequenceSum(temp2));
    }
};