class Solution {
public:
    int characterReplacement(string s, int k) {
             int n = s.size();
        int left = 0, right = 0, maxFreq = 0, maxLen = 0;
        int hash[26] = {0};
        while(right<n){
            hash[s[right]-'A']++; // Character frequency
            if(hash[s[right]-'A'] > maxFreq){
                maxFreq = hash[s[right]-'A'];
            };
            if((right-left+1)-maxFreq > k){ //trimming the left portion
                hash[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};