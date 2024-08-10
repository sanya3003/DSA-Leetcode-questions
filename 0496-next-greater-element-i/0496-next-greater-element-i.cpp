class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        stack<int> st;
        unordered_map<int, int> nextGreaterMap;
        
        // Process arr to find the next greater element for each element
        for (int num : arr) {
            while (!st.empty() && st.top() < num) {
                nextGreaterMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // Elements remaining in the stack do not have a next greater element
        while (!st.empty()) {
            nextGreaterMap[st.top()] = -1;
            st.pop();
        }
        
        // Build the result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }
        
        return result;
    }
};