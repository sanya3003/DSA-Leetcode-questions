class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; // stores index in monotonic increasing order of cumulativesum
        vector<long long> cumulativeSum(n,0); // stores the cumulativeSum

        int result = INT_MAX; //need to find the minimum size subarray whose sum>=k
        int j = 0;

        while(j<n){
            if(j==0){
                cumulativeSum[j] = nums[j];
            } else{
                cumulativeSum[j] = cumulativeSum[j-1] + nums[j];
            }

            if(cumulativeSum[j] >= k){
                result = min(result, j+1);
            }

            // need to shrink the window or not 
            while(!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= k){
                result = min(result, j - deq.front());
                deq.pop_front();

            }
            while(!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(j);
            j++;
        }
        return result == INT_MAX ? -1 : result;

        
    }
};