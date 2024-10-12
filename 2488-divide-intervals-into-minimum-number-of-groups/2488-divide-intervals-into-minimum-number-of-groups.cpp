class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // step 1 - sort based on starting point
        sort(begin(intervals), end(intervals));
        // step 2 - define min-heap to store ending points of each group
        priority_queue<int, vector<int>, greater<int>> pq;

        // step 3 - process each interval one by one
        for(vector<int>& interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && start>pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        // step 4 size of heap 
        return pq.size();
    }
};