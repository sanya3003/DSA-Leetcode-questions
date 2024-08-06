class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;

        // 2,3,4,5,6,7,8,9
        unordered_map<int, int> mp;// int arr[10]-> 0 to 9
        int assign_key = 2;
        for(char &ch : word){
            if(assign_key > 9){
                assign_key = 2;
            }
            mp[assign_key]++;
            result += mp[assign_key];

            assign_key++;
        }
        return result;
    }
};