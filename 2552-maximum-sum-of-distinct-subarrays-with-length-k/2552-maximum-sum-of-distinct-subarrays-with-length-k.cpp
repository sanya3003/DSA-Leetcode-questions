class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long result = 0;
        long long currWindowSum = 0;

        unordered_set<int> st;

        int i = 0;
        int j = 0;
        // if i wamt to check that at what index i have seen that element previoisly i can use map to store it 

        while(j<n){
            // check if nums[j] is already present in the window nums[i..j]
            while(st.count(nums[j])){
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                result = max(result, currWindowSum);
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
        
    }
};