class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Convert map to vector of pairs
        vector<pair<int, int>> freqPairs;
        for (auto& entry : frequencyMap) {
            freqPairs.push_back({entry.first, entry.second});
        }

        // Step 3: Perform merge sort based on frequency
        mergeSort(freqPairs, 0, freqPairs.size() - 1);

        // Step 4: Extract the top k elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqPairs[i].first);
        }

        return result;
    }

private:
    // Merge sort implementation
    void mergeSort(vector<pair<int, int>>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        // Merge based on frequency
        while (i <= mid && j <= right) {
            if (arr[i].second >= arr[j].second) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy back to the original array
        for (int p = 0; p < temp.size(); ++p) {
            arr[left + p] = temp[p];
        }
    }
};